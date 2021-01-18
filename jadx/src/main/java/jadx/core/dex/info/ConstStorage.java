package jadx.core.dex.info;

import org.jetbrains.annotations.Nullable;

import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import jadx.api.IJadxArgs;
import jadx.core.dex.attributes.AType;
import jadx.core.dex.instructions.args.LiteralArg;
import jadx.core.dex.instructions.args.PrimitiveType;
import jadx.core.dex.nodes.ClassNode;
import jadx.core.dex.nodes.DexNode;
import jadx.core.dex.nodes.FieldNode;
import jadx.core.dex.nodes.ResRefField;
import jadx.core.dex.nodes.parser.FieldInitAttr;

public class ConstStorage {

    private final boolean replaceEnabled;
    private final Values globalValues = new Values();
    private final Map<ClassNode, Values> classes = new HashMap<ClassNode, Values>();
    private Map<Integer, String> resourcesNames = new HashMap<Integer, String>();

    public ConstStorage(IJadxArgs args) {
        this.replaceEnabled = args.isReplaceConsts();
    }

    public void processConstFields(ClassNode cls, List<FieldNode> staticFields) {
        if (!replaceEnabled || staticFields.isEmpty()) {
            return;
        }
        for (FieldNode f : staticFields) {
            AccessInfo accFlags = f.getAccessFlags();
            if (accFlags.isStatic() && accFlags.isFinal()) {
                FieldInitAttr fv = f.get(AType.FIELD_INIT);
                if (fv != null
                        && fv.getValue() != null
                        && fv.getValueType() == FieldInitAttr.InitType.CONST
                        && fv != FieldInitAttr.NULL_VALUE) {
                    addConstField(cls, f, fv.getValue(), accFlags.isPublic());
                }
            }
        }
    }

    private void addConstField(ClassNode cls, FieldNode fld, Object value, boolean isPublic) {
        if (isPublic) {
            globalValues.put(value, fld);
        } else {
            getClsValues(cls).put(value, fld);
        }
    }

    private Values getClsValues(ClassNode cls) {
        Values classValues = classes.get(cls);
        if (classValues == null) {
            classValues = new Values();
            classes.put(cls, classValues);
        }
        return classValues;
    }

    @Nullable
    public FieldNode getConstField(ClassNode cls, Object value, boolean searchGlobal) {
        DexNode dex = cls.dex();
        if (value instanceof Integer) {
            String str = resourcesNames.get(value);
            if (str != null) {
                return new ResRefField(dex, str.replace('/', '.'));
            }
        }
        if (!replaceEnabled) {
            return null;
        }
        boolean foundInGlobal = globalValues.contains(value);
        if (foundInGlobal && !searchGlobal) {
            return null;
        }
        ClassNode current = cls;
        while (current != null) {
            Values classValues = classes.get(current);
            if (classValues != null) {
                FieldNode field = classValues.get(value);
                if (field != null) {
                    if (foundInGlobal) {
                        return null;
                    }
                    return field;
                }
            }
            ClassInfo parentClass = current.getClassInfo().getParentClass();
            if (parentClass == null) {
                break;
            }
            current = dex.resolveClass(parentClass);
        }
        if (searchGlobal) {
            return globalValues.get(value);
        }
        return null;
    }

    @Nullable
    public FieldNode getConstFieldByLiteralArg(ClassNode cls, LiteralArg arg) {
        PrimitiveType type = arg.getType().getPrimitiveType();
        if (type == null) {
            return null;
        }
        long literal = arg.getLiteral();
        switch (type) {
            case BOOLEAN:
                return getConstField(cls, literal == 1, false);
            case CHAR:
                return getConstField(cls, (char) literal, Math.abs(literal) > 10);
            case BYTE:
                return getConstField(cls, (byte) literal, Math.abs(literal) > 10);
            case SHORT:
                return getConstField(cls, (short) literal, Math.abs(literal) > 100);
            case INT:
                return getConstField(cls, (int) literal, Math.abs(literal) > 100);
            case LONG:
                return getConstField(cls, literal, Math.abs(literal) > 1000);
            case FLOAT:
                float f = Float.intBitsToFloat((int) literal);
                return getConstField(cls, f, f != 0.0);
            case DOUBLE:
                double d = Double.longBitsToDouble(literal);
                return getConstField(cls, d, d != 0);
        }
        return null;
    }

    public Map<Integer, String> getResourcesNames() {
        return resourcesNames;
    }

    public void setResourcesNames(Map<Integer, String> resourcesNames) {
        this.resourcesNames = resourcesNames;
    }

    public Map<Object, FieldNode> getGlobalConstFields() {
        return globalValues.getValues();
    }

    public boolean isReplaceEnabled() {
        return replaceEnabled;
    }

    private static final class Values {
        private final Map<Object, FieldNode> values = new HashMap<Object, FieldNode>();
        private final Set<Object> duplicates = new HashSet<Object>();

        public Map<Object, FieldNode> getValues() {
            return values;
        }

        public FieldNode get(Object key) {
            return values.get(key);
        }

        /**
         * @return true if this value is duplicated
         */
        public boolean put(Object value, FieldNode fld) {
            FieldNode prev = values.put(value, fld);
            if (prev != null) {
                values.remove(value);
                duplicates.add(value);
                return true;
            }
            if (duplicates.contains(value)) {
                values.remove(value);
                return true;
            }
            return false;
        }

        public boolean contains(Object value) {
            return duplicates.contains(value) || values.containsKey(value);
        }
    }
}
