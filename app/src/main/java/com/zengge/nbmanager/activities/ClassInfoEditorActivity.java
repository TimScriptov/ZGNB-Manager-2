package com.zengge.nbmanager.activities;

import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.KeyEvent;
import android.widget.Toast;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.AppCompatEditText;

import com.zengge.nbmanager.R;

import org.jf.dexlib.ClassDefItem;
import org.jf.dexlib.DexFile;
import org.jf.dexlib.StringIdItem;
import org.jf.dexlib.TypeIdItem;
import org.jf.dexlib.TypeListItem;
import org.jf.dexlib.Util.AccessFlags;

import java.util.ArrayList;
import java.util.regex.Pattern;

public class ClassInfoEditorActivity extends AppCompatActivity {
    public static final Pattern pattern = Pattern.compile("\\s");
    private AppCompatEditText accessFlagsEdit;
    private AppCompatEditText superclassEdit;
    private AppCompatEditText interfacesEdit;
    private AppCompatEditText sourceFileEdit;
    private boolean isChanged;
    private ClassDefItem classDef;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.class_info_editor);
        TextWatcher watch = new TextWatcher() {
            public void beforeTextChanged(CharSequence c, int start, int count,
                                          int after) {
            }

            public void onTextChanged(CharSequence c, int start, int count,
                                      int after) {
            }

            public void afterTextChanged(Editable edit) {
                if (!isChanged)
                    isChanged = true;
            }
        };
        accessFlagsEdit = findViewById(R.id.access_flags_edit);
        accessFlagsEdit.addTextChangedListener(watch);
        superclassEdit = findViewById(R.id.super_class_edit);
        superclassEdit.addTextChangedListener(watch);
        interfacesEdit = findViewById(R.id.interface_edit);
        interfacesEdit.addTextChangedListener(watch);
        sourceFileEdit = findViewById(R.id.source_file_edit);
        sourceFileEdit.addTextChangedListener(watch);
        init();
    }

    private void init() {
        classDef = ClassListActivity.curClassDef;
        accessFlagsEdit.setText(AccessFlags.formatAccessFlagsForClass(classDef
                .getAccessFlags()));
        String superClassName = classDef.getSuperclass().getTypeDescriptor();
        superclassEdit.setText(superClassName);
        // interfaces
        String interfaces = classDef.getInterfaces() != null ? classDef
                .getInterfaces().getTypeListString(" ") : "";
        interfacesEdit.setText(interfaces);
        String source = classDef.getSourceFile() != null ? classDef
                .getSourceFile().getStringValue() : "";
        sourceFileEdit.setText(source);
        isChanged = false;
    }

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == KeyEvent.KEYCODE_BACK) {
            if (isChanged) {
                MainActivity.prompt(this, getString(R.string.prompt),
                        getString(R.string.is_save),
                        (dailog, which) -> {
                            if (which == AlertDialog.BUTTON_POSITIVE) {
                                save(ClassListActivity.dexFile);
                                finish();
                            } else if (which == AlertDialog.BUTTON_NEGATIVE)
                                finish();
                        });
                return true;
            }
        }
        return super.onKeyDown(keyCode, event);
    }

    private void save(DexFile dexFile) {
        // Access Flags
        String[] str;
        int accessFlags = 0;
        try {
            String ac = accessFlagsEdit.getText().toString();
            if (ac != null && !ac.equals("")) {
                str = pattern.split(accessFlagsEdit.getText().toString());
                if (str != null) {
                    for (String s : str) {
                        AccessFlags accessFlag = AccessFlags.getAccessFlag(s);
                        accessFlags |= accessFlag.getValue();
                    }
                }
            }
            classDef.accessFlags = accessFlags;
        } catch (Exception e) {
            MainActivity.showMessage(this, "", "Access Flag Error ");
        }
        // super class
        classDef.superType = TypeIdItem.internTypeIdItem(dexFile,
                superclassEdit.getText().toString());
        // interfaces
        ArrayList<TypeIdItem> types = new ArrayList<TypeIdItem>();
        String in = interfacesEdit.getText().toString();
        if (in != null && !in.equals("")) {
            str = pattern.split(in);
            if (str != null) {
                for (String s : str) {
                    if (s.equals(""))
                        continue;
                    types.add(TypeIdItem.internTypeIdItem(dexFile, s));
                }
            }
        }
        TypeListItem typeList = null;
        if (types.size() > 0)
            typeList = TypeListItem.internTypeListItem(dexFile, types);
        classDef.implementedInterfaces = typeList;
        String sourceFile = sourceFileEdit.getText().toString().trim();
        if (!sourceFile.equals("")) {
            classDef.sourceFile = StringIdItem.internStringIdItem(dexFile,
                    sourceFile);
        } else
            classDef.sourceFile = null;
        ClassListActivity.isChanged = true;
        isChanged = false;
    }

    public void toast(String message) {
        Toast.makeText(this, message, Toast.LENGTH_SHORT).show();
    }

    private void clearAll() {
        classDef = null;
        accessFlagsEdit = null;
        superclassEdit = null;
        interfacesEdit = null;
        sourceFileEdit = null;
        System.gc();
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        clearAll();
    }
}
