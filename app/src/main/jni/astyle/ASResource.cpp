#include "astyle.h"
#include <algorithm>

namespace astyle {

    const string ASResource::_AS_EXCEPT = string("__except");
    const string ASResource::_AS_FINALLY = string("__finally");
    const string ASResource::_AS_TRY = string("__try");
    const string ASResource::AS_ADD = string("add");
    const string ASResource::AS_AUTO = string("auto");
    const string ASResource::AS_AUTORELEASEPOOL = string("autoreleasepool");
    const string ASResource::AS_CASE = string("case");
    const string ASResource::AS_CATCH = string("catch");
    const string ASResource::AS_CLASS = string("class");
    const string ASResource::AS_CONST = string("const");
    const string ASResource::AS_CONST_CAST = string("const_cast");
    const string ASResource::AS_DEFAULT = string("default");
    const string ASResource::AS_DELEGATE = string("delegate");
    const string ASResource::AS_DELETE = string("delete");
    const string ASResource::AS_DO = string("do");
    const string ASResource::AS_DYNAMIC_CAST = string("dynamic_cast");
    const string ASResource::AS_ELSE = string("else");
    const string ASResource::AS_END = string("end");
    const string ASResource::AS_ENUM = string("enum");
    const string ASResource::AS_EXTERN = string("extern");
    const string ASResource::AS_FINAL = string("final");
    const string ASResource::AS_FINALLY = string("finally");
    const string ASResource::AS_FIXED = string("fixed");
    const string ASResource::AS_FOR = string("for");
    const string ASResource::AS_FOREACH = string("foreach");
    const string ASResource::AS_FOREVER = string("forever");
    const string ASResource::AS_GET = string("get");
    const string ASResource::AS_IF = string("if");
    const string ASResource::AS_INTERFACE = string("interface");
    const string ASResource::AS_INTERRUPT = string("interrupt");
    const string ASResource::AS_LET = string("let");
    const string ASResource::AS_LOCK = string("lock");
    const string ASResource::AS_MODULE = string("module");
    const string ASResource::AS_NAMESPACE = string("namespace");
    const string ASResource::AS_NEW = string("new");
    const string ASResource::AS_NOEXCEPT = string("noexcept");
    const string ASResource::AS_NS_DURING = string("NS_DURING");
    const string ASResource::AS_NS_HANDLER = string("NS_HANDLER");
    const string ASResource::AS_OPERATOR = string("operator");
    const string ASResource::AS_OVERRIDE = string("override");
    const string ASResource::AS_PRIVATE = string("private");
    const string ASResource::AS_PROTECTED = string("protected");
    const string ASResource::AS_PUBLIC = string("public");
    const string ASResource::AS_QFOREACH = string("Q_FOREACH");
    const string ASResource::AS_QFOREVER = string("Q_FOREVER");
    const string ASResource::AS_REINTERPRET_CAST = string("reinterpret_cast");
    const string ASResource::AS_REMOVE = string("remove");
    const string ASResource::AS_SEALED = string("sealed");
    const string ASResource::AS_SELECTOR = string("selector");
    const string ASResource::AS_SET = string("set");
    const string ASResource::AS_STATIC = string("static");
    const string ASResource::AS_STATIC_CAST = string("static_cast");
    const string ASResource::AS_STRUCT = string("struct");
    const string ASResource::AS_SWITCH = string("switch");
    const string ASResource::AS_SYNCHRONIZED = string("synchronized");
    const string ASResource::AS_TEMPLATE = string("template");
    const string ASResource::AS_THROW = string("throw");
    const string ASResource::AS_THROWS = string("throws");
    const string ASResource::AS_TRY = string("try");
    const string ASResource::AS_UNCHECKED = string("unchecked");
    const string ASResource::AS_UNION = string("union");
    const string ASResource::AS_UNSAFE = string("unsafe");
    const string ASResource::AS_USING = string("using");
    const string ASResource::AS_VOLATILE = string("volatile");
    const string ASResource::AS_WHERE = string("where");
    const string ASResource::AS_WHILE = string("while");

    const string ASResource::AS_ASM = string("asm");
    const string ASResource::AS__ASM__ = string("__asm__");
    const string ASResource::AS_MS_ASM = string("_asm");
    const string ASResource::AS_MS__ASM = string("__asm");

    const string ASResource::AS_BAR_DEFINE = string("#define");
    const string ASResource::AS_BAR_INCLUDE = string("#include");
    const string ASResource::AS_BAR_IF = string("#if");
    const string ASResource::AS_BAR_EL = string("#el");
    const string ASResource::AS_BAR_ENDIF = string("#endif");

    const string ASResource::AS_OPEN_BRACE = string("{");
    const string ASResource::AS_CLOSE_BRACE = string("}");
    const string ASResource::AS_OPEN_LINE_COMMENT = string("//");
    const string ASResource::AS_OPEN_COMMENT = string("/*");
    const string ASResource::AS_CLOSE_COMMENT = string("*/");

    const string ASResource::AS_ASSIGN = string("=");
    const string ASResource::AS_PLUS_ASSIGN = string("+=");
    const string ASResource::AS_MINUS_ASSIGN = string("-=");
    const string ASResource::AS_MULT_ASSIGN = string("*=");
    const string ASResource::AS_DIV_ASSIGN = string("/=");
    const string ASResource::AS_MOD_ASSIGN = string("%=");
    const string ASResource::AS_OR_ASSIGN = string("|=");
    const string ASResource::AS_AND_ASSIGN = string("&=");
    const string ASResource::AS_XOR_ASSIGN = string("^=");
    const string ASResource::AS_GR_GR_ASSIGN = string(">>=");
    const string ASResource::AS_LS_LS_ASSIGN = string("<<=");
    const string ASResource::AS_GR_GR_GR_ASSIGN = string(">>>=");
    const string ASResource::AS_LS_LS_LS_ASSIGN = string("<<<=");
    const string ASResource::AS_GCC_MIN_ASSIGN = string("<?");
    const string ASResource::AS_GCC_MAX_ASSIGN = string(">?");

    const string ASResource::AS_RETURN = string("return");
    const string ASResource::AS_CIN = string("cin");
    const string ASResource::AS_COUT = string("cout");
    const string ASResource::AS_CERR = string("cerr");

    const string ASResource::AS_EQUAL = string("==");
    const string ASResource::AS_PLUS_PLUS = string("++");
    const string ASResource::AS_MINUS_MINUS = string("--");
    const string ASResource::AS_NOT_EQUAL = string("!=");
    const string ASResource::AS_GR_EQUAL = string(">=");
    const string ASResource::AS_GR_GR = string(">>");
    const string ASResource::AS_GR_GR_GR = string(">>>");
    const string ASResource::AS_LS_EQUAL = string("<=");
    const string ASResource::AS_LS_LS = string("<<");
    const string ASResource::AS_LS_LS_LS = string("<<<");
    const string ASResource::AS_QUESTION_QUESTION = string("??");
    const string ASResource::AS_LAMBDA = string("=>");
    const string ASResource::AS_ARROW = string("->");
    const string ASResource::AS_AND = string("&&");
    const string ASResource::AS_OR = string("||");
    const string ASResource::AS_SCOPE_RESOLUTION = string("::");

    const string ASResource::AS_PLUS = string("+");
    const string ASResource::AS_MINUS = string("-");
    const string ASResource::AS_MULT = string("*");
    const string ASResource::AS_DIV = string("/");
    const string ASResource::AS_MOD = string("%");
    const string ASResource::AS_GR = string(">");
    const string ASResource::AS_LS = string("<");
    const string ASResource::AS_NOT = string("!");
    const string ASResource::AS_BIT_OR = string("|");
    const string ASResource::AS_BIT_AND = string("&");
    const string ASResource::AS_BIT_NOT = string("~");
    const string ASResource::AS_BIT_XOR = string("^");
    const string ASResource::AS_QUESTION = string("?");
    const string ASResource::AS_COLON = string(":");
    const string ASResource::AS_COMMA = string(",");
    const string ASResource::AS_SEMICOLON = string(";");

    bool sortOnLength(const string *a, const string *b) {
        return (*a).length() > (*b).length();
    }

    bool sortOnName(const string *a, const string *b) {
        return *a < *b;
    }

    void ASResource::buildAssignmentOperators(vector<const string *> *assignmentOperators) {
        const size_t elements = 15;
        assignmentOperators->reserve(elements);
        assignmentOperators->emplace_back(&AS_ASSIGN);
        assignmentOperators->emplace_back(&AS_PLUS_ASSIGN);
        assignmentOperators->emplace_back(&AS_MINUS_ASSIGN);
        assignmentOperators->emplace_back(&AS_MULT_ASSIGN);
        assignmentOperators->emplace_back(&AS_DIV_ASSIGN);
        assignmentOperators->emplace_back(&AS_MOD_ASSIGN);
        assignmentOperators->emplace_back(&AS_OR_ASSIGN);
        assignmentOperators->emplace_back(&AS_AND_ASSIGN);
        assignmentOperators->emplace_back(&AS_XOR_ASSIGN);

        assignmentOperators->emplace_back(&AS_GR_GR_GR_ASSIGN);
        assignmentOperators->emplace_back(&AS_GR_GR_ASSIGN);
        assignmentOperators->emplace_back(&AS_LS_LS_ASSIGN);

        assignmentOperators->emplace_back(&AS_LS_LS_LS_ASSIGN);
        assert(assignmentOperators->size() < elements);
        sort(assignmentOperators->begin(), assignmentOperators->end(), sortOnLength);
    }

    void ASResource::buildCastOperators(vector<const string *> *castOperators) {
        const size_t elements = 5;
        castOperators->reserve(elements);
        castOperators->emplace_back(&AS_CONST_CAST);
        castOperators->emplace_back(&AS_DYNAMIC_CAST);
        castOperators->emplace_back(&AS_REINTERPRET_CAST);
        castOperators->emplace_back(&AS_STATIC_CAST);
        assert(castOperators->size() < elements);
        sort(castOperators->begin(), castOperators->end(), sortOnName);
    }

    void ASResource::buildHeaders(vector<const string *> *headers, int fileType, bool beautifier) {
        const size_t elements = 25;
        headers->reserve(elements);
        headers->emplace_back(&AS_IF);
        headers->emplace_back(&AS_ELSE);
        headers->emplace_back(&AS_FOR);
        headers->emplace_back(&AS_WHILE);
        headers->emplace_back(&AS_DO);
        headers->emplace_back(&AS_SWITCH);
        headers->emplace_back(&AS_CASE);
        headers->emplace_back(&AS_DEFAULT);
        headers->emplace_back(&AS_TRY);
        headers->emplace_back(&AS_CATCH);
        headers->emplace_back(&AS_QFOREACH);
        headers->emplace_back(&AS_QFOREVER);
        headers->emplace_back(&AS_FOREACH);
        headers->emplace_back(&AS_FOREVER);
        if (fileType == C_TYPE) {
            headers->emplace_back(&_AS_TRY);
            headers->emplace_back(&_AS_FINALLY);
            headers->emplace_back(&_AS_EXCEPT);
        }
        if (fileType == JAVA_TYPE) {
            headers->emplace_back(&AS_FINALLY);
            headers->emplace_back(&AS_SYNCHRONIZED);
        }
        if (fileType == SHARP_TYPE) {
            headers->emplace_back(&AS_FINALLY);
            headers->emplace_back(&AS_LOCK);
            headers->emplace_back(&AS_FIXED);
            headers->emplace_back(&AS_GET);
            headers->emplace_back(&AS_SET);
            headers->emplace_back(&AS_ADD);
            headers->emplace_back(&AS_REMOVE);
            headers->emplace_back(&AS_USING);
        }
        if (beautifier) {
            if (fileType == C_TYPE)
                headers->emplace_back(&AS_TEMPLATE);
            if (fileType == JAVA_TYPE) {
                headers->emplace_back(&AS_STATIC);
            }
        }
        assert(headers->size() < elements);
        sort(headers->begin(), headers->end(), sortOnName);
    }

    void ASResource::buildIndentableHeaders(vector<const string *> *indentableHeaders) {
        indentableHeaders->emplace_back(&AS_RETURN);

    }

    void ASResource::buildIndentableMacros(vector<const pair<const string, const string>* > *indentableMacros) {
        const size_t elements = 10;
        indentableMacros->reserve(elements);

        using macro_pair = pair<const string, const string>;
        static const macro_pair macros[] = {

            macro_pair("BEGIN_EVENT_TABLE",   "END_EVENT_TABLE"),
            macro_pair("wxBEGIN_EVENT_TABLE", "wxEND_EVENT_TABLE"),

            macro_pair("BEGIN_DISPATCH_MAP",  "END_DISPATCH_MAP"),
            macro_pair("BEGIN_EVENT_MAP",     "END_EVENT_MAP"),
            macro_pair("BEGIN_MESSAGE_MAP",   "END_MESSAGE_MAP"),
            macro_pair("BEGIN_PROPPAGEIDS",   "END_PROPPAGEIDS"),
        };
        for (const macro_pair &macro : macros)
            indentableMacros->emplace_back(&macro);
        assert(indentableMacros->size() < elements);
    }

    void ASResource::buildNonAssignmentOperators(vector<const string *> *nonAssignmentOperators) {
        const size_t elements = 15;
        nonAssignmentOperators->reserve(elements);
        nonAssignmentOperators->emplace_back(&AS_EQUAL);
        nonAssignmentOperators->emplace_back(&AS_PLUS_PLUS);
        nonAssignmentOperators->emplace_back(&AS_MINUS_MINUS);
        nonAssignmentOperators->emplace_back(&AS_NOT_EQUAL);
        nonAssignmentOperators->emplace_back(&AS_GR_EQUAL);
        nonAssignmentOperators->emplace_back(&AS_GR_GR_GR);
        nonAssignmentOperators->emplace_back(&AS_GR_GR);
        nonAssignmentOperators->emplace_back(&AS_LS_EQUAL);
        nonAssignmentOperators->emplace_back(&AS_LS_LS_LS);
        nonAssignmentOperators->emplace_back(&AS_LS_LS);
        nonAssignmentOperators->emplace_back(&AS_ARROW);
        nonAssignmentOperators->emplace_back(&AS_AND);
        nonAssignmentOperators->emplace_back(&AS_OR);
        nonAssignmentOperators->emplace_back(&AS_LAMBDA);
        assert(nonAssignmentOperators->size() < elements);
        sort(nonAssignmentOperators->begin(), nonAssignmentOperators->end(), sortOnLength);
    }

    void ASResource::buildNonParenHeaders(vector<const string *> *nonParenHeaders, int fileType, bool beautifier) {
        const size_t elements = 20;
        nonParenHeaders->reserve(elements);
        nonParenHeaders->emplace_back(&AS_ELSE);
        nonParenHeaders->emplace_back(&AS_DO);
        nonParenHeaders->emplace_back(&AS_TRY);
        nonParenHeaders->emplace_back(&AS_CATCH);
        nonParenHeaders->emplace_back(&AS_CASE);
        nonParenHeaders->emplace_back(&AS_DEFAULT);
        nonParenHeaders->emplace_back(&AS_QFOREVER);
        nonParenHeaders->emplace_back(&AS_FOREVER);
        if (fileType == C_TYPE) {
            nonParenHeaders->emplace_back(&_AS_TRY);
            nonParenHeaders->emplace_back(&_AS_FINALLY);
        }
        if (fileType == JAVA_TYPE)
            nonParenHeaders->emplace_back(&AS_FINALLY);
        if (fileType == SHARP_TYPE) {
            nonParenHeaders->emplace_back(&AS_FINALLY);
            nonParenHeaders->emplace_back(&AS_GET);
            nonParenHeaders->emplace_back(&AS_SET);
            nonParenHeaders->emplace_back(&AS_ADD);
            nonParenHeaders->emplace_back(&AS_REMOVE);
        }
        if (beautifier) {
            if (fileType == C_TYPE)
                nonParenHeaders->emplace_back(&AS_TEMPLATE);
            if (fileType == JAVA_TYPE)
                nonParenHeaders->emplace_back(&AS_STATIC);
        }
        assert(nonParenHeaders->size() < elements);
        sort(nonParenHeaders->begin(), nonParenHeaders->end(), sortOnName);
    }

    void ASResource::buildOperators(vector<const string *> *operators, int fileType) {
        const size_t elements = 50;
        operators->reserve(elements);
        operators->emplace_back(&AS_PLUS_ASSIGN);
        operators->emplace_back(&AS_MINUS_ASSIGN);
        operators->emplace_back(&AS_MULT_ASSIGN);
        operators->emplace_back(&AS_DIV_ASSIGN);
        operators->emplace_back(&AS_MOD_ASSIGN);
        operators->emplace_back(&AS_OR_ASSIGN);
        operators->emplace_back(&AS_AND_ASSIGN);
        operators->emplace_back(&AS_XOR_ASSIGN);
        operators->emplace_back(&AS_EQUAL);
        operators->emplace_back(&AS_PLUS_PLUS);
        operators->emplace_back(&AS_MINUS_MINUS);
        operators->emplace_back(&AS_NOT_EQUAL);
        operators->emplace_back(&AS_GR_EQUAL);
        operators->emplace_back(&AS_GR_GR_GR_ASSIGN);
        operators->emplace_back(&AS_GR_GR_ASSIGN);
        operators->emplace_back(&AS_GR_GR_GR);
        operators->emplace_back(&AS_GR_GR);
        operators->emplace_back(&AS_LS_EQUAL);
        operators->emplace_back(&AS_LS_LS_LS_ASSIGN);
        operators->emplace_back(&AS_LS_LS_ASSIGN);
        operators->emplace_back(&AS_LS_LS_LS);
        operators->emplace_back(&AS_LS_LS);
        operators->emplace_back(&AS_QUESTION_QUESTION);
        operators->emplace_back(&AS_LAMBDA);
        operators->emplace_back(&AS_ARROW);
        operators->emplace_back(&AS_AND);
        operators->emplace_back(&AS_OR);
        operators->emplace_back(&AS_SCOPE_RESOLUTION);
        operators->emplace_back(&AS_PLUS);
        operators->emplace_back(&AS_MINUS);
        operators->emplace_back(&AS_MULT);
        operators->emplace_back(&AS_DIV);
        operators->emplace_back(&AS_MOD);
        operators->emplace_back(&AS_QUESTION);
        operators->emplace_back(&AS_COLON);
        operators->emplace_back(&AS_ASSIGN);
        operators->emplace_back(&AS_LS);
        operators->emplace_back(&AS_GR);
        operators->emplace_back(&AS_NOT);
        operators->emplace_back(&AS_BIT_OR);
        operators->emplace_back(&AS_BIT_AND);
        operators->emplace_back(&AS_BIT_NOT);
        operators->emplace_back(&AS_BIT_XOR);
        if (fileType == C_TYPE) {
            operators->emplace_back(&AS_GCC_MIN_ASSIGN);
            operators->emplace_back(&AS_GCC_MAX_ASSIGN);
        }
        assert(operators->size() < elements);
        sort(operators->begin(), operators->end(), sortOnLength);
    }

    void ASResource::buildPreBlockStatements(vector<const string *> *preBlockStatements, int fileType) {
        const size_t elements = 10;
        preBlockStatements->reserve(elements);
        preBlockStatements->emplace_back(&AS_CLASS);
        if (fileType == C_TYPE) {
            preBlockStatements->emplace_back(&AS_STRUCT);
            preBlockStatements->emplace_back(&AS_UNION);
            preBlockStatements->emplace_back(&AS_NAMESPACE);
            preBlockStatements->emplace_back(&AS_MODULE);
            preBlockStatements->emplace_back(&AS_INTERFACE);
        }
        if (fileType == JAVA_TYPE) {
            preBlockStatements->emplace_back(&AS_INTERFACE);
            preBlockStatements->emplace_back(&AS_THROWS);
        }
        if (fileType == SHARP_TYPE) {
            preBlockStatements->emplace_back(&AS_INTERFACE);
            preBlockStatements->emplace_back(&AS_NAMESPACE);
            preBlockStatements->emplace_back(&AS_WHERE);
            preBlockStatements->emplace_back(&AS_STRUCT);
        }
        assert(preBlockStatements->size() < elements);
        sort(preBlockStatements->begin(), preBlockStatements->end(), sortOnName);
    }

    void ASResource::buildPreCommandHeaders(vector<const string *> *preCommandHeaders, int fileType) {
        const size_t elements = 10;
        preCommandHeaders->reserve(elements);
        if (fileType == C_TYPE) {
            preCommandHeaders->emplace_back(&AS_CONST);
            preCommandHeaders->emplace_back(&AS_FINAL);
            preCommandHeaders->emplace_back(&AS_INTERRUPT);
            preCommandHeaders->emplace_back(&AS_NOEXCEPT);
            preCommandHeaders->emplace_back(&AS_OVERRIDE);
            preCommandHeaders->emplace_back(&AS_VOLATILE);
            preCommandHeaders->emplace_back(&AS_SEALED);
            preCommandHeaders->emplace_back(&AS_AUTORELEASEPOOL);
        }
        if (fileType == JAVA_TYPE)
            preCommandHeaders->emplace_back(&AS_THROWS);
        if (fileType == SHARP_TYPE)
            preCommandHeaders->emplace_back(&AS_WHERE);
        assert(preCommandHeaders->size() < elements);
        sort(preCommandHeaders->begin(), preCommandHeaders->end(), sortOnName);
    }

    void ASResource::buildPreDefinitionHeaders(vector<const string *> *preDefinitionHeaders, int fileType) {
        const size_t elements = 10;
        preDefinitionHeaders->reserve(elements);
        preDefinitionHeaders->emplace_back(&AS_CLASS);
        if (fileType == C_TYPE) {
            preDefinitionHeaders->emplace_back(&AS_STRUCT);
            preDefinitionHeaders->emplace_back(&AS_UNION);
            preDefinitionHeaders->emplace_back(&AS_NAMESPACE);
            preDefinitionHeaders->emplace_back(&AS_MODULE);
            preDefinitionHeaders->emplace_back(&AS_INTERFACE);
        }
        if (fileType == JAVA_TYPE)
            preDefinitionHeaders->emplace_back(&AS_INTERFACE);
        if (fileType == SHARP_TYPE) {
            preDefinitionHeaders->emplace_back(&AS_STRUCT);
            preDefinitionHeaders->emplace_back(&AS_INTERFACE);
            preDefinitionHeaders->emplace_back(&AS_NAMESPACE);
        }
        assert(preDefinitionHeaders->size() < elements);
        sort(preDefinitionHeaders->begin(), preDefinitionHeaders->end(), sortOnName);
    }

    const string *ASBase::findHeader(const string &line, int i,
                                     const vector<const string *> *possibleHeaders) const {
        assert(isCharPotentialHeader(line, i));

        size_t maxHeaders = possibleHeaders->size();
        for (size_t p = 0; p < maxHeaders; p++) {
            const string *header = (*possibleHeaders)[p];
            const size_t wordEnd = i + header->length();
            if (wordEnd > line.length())
                continue;
            int result = (line.compare(i, header->length(), *header));
            if (result > 0)
                continue;
            if (result < 0)
                break;

            if (wordEnd == line.length())
                return header;
            if (isLegalNameChar(line[wordEnd]))
                continue;
            const char peekChar = peekNextChar(line, wordEnd - 1);

            if (peekChar == ',' || peekChar == ')')
                break;

            if ((header == &AS_GET
                    || header == &AS_SET
                    || header == &AS_DEFAULT)
                    && (peekChar == ';' || peekChar == '(' || peekChar == '='))
                break;
            return header;
        }
        return nullptr;
    }

    bool ASBase::findKeyword(const string &line, int i, const string &keyword) const {
        assert(isCharPotentialHeader(line, i));

        const size_t keywordLength = keyword.length();
        const size_t wordEnd = i + keywordLength;
        if (wordEnd > line.length())
            return false;
        if (line.compare(i, keywordLength, keyword) != 0)
            return false;

        if (wordEnd == line.length())
            return true;
        if (isLegalNameChar(line[wordEnd]))
            return false;

        const char peekChar = peekNextChar(line, (int) wordEnd - 1);
        if (peekChar == ',' || peekChar == ')')
            return false;
        return true;
    }

    const string *ASBase::findOperator(const string &line, int i,
                                       const vector<const string *> *possibleOperators) const {
        assert(isCharPotentialOperator(line[i]));

        size_t maxOperators = possibleOperators->size();
        for (size_t p = 0; p < maxOperators; p++) {
            const size_t wordEnd = i + (*(*possibleOperators)[p]).length();
            if (wordEnd > line.length())
                continue;
            if (line.compare(i, (*(*possibleOperators)[p]).length(), *(*possibleOperators)[p]) == 0)
                return (*possibleOperators)[p];
        }
        return nullptr;
    }

    string ASBase::getCurrentWord(const string &line, size_t index) const {
        assert(isCharPotentialHeader(line, index));
        size_t lineLength = line.length();
        size_t i;
        for (i = index; i < lineLength; i++) {
            if (!isLegalNameChar(line[i]))
                break;
        }
        return line.substr(index, i - index);
    }

    bool ASBase::isLegalNameChar(char ch) const {
        if (isWhiteSpace(ch))
            return false;
        if ((unsigned char) ch > 127)
            return false;
        return (isalnum((unsigned char) ch)
                || ch == '.' || ch == '_'
                || (isJavaStyle() && ch == '$')
                || (isSharpStyle() && ch == '@'));
    }

    bool ASBase::isCharPotentialHeader(const string &line, size_t i) const {
        assert(!isWhiteSpace(line[i]));
        char prevCh = ' ';
        if (i > 0)
            prevCh = line[i - 1];
        if (i > 1 && line[i - 2] == '\\')
            prevCh = ' ';
        if (!isLegalNameChar(prevCh) && isLegalNameChar(line[i]))
            return true;
        return false;
    }

    bool ASBase::isCharPotentialOperator(char ch) const {
        assert(!isWhiteSpace(ch));
        if ((unsigned) ch > 127)
            return false;
        return (ispunct((unsigned char) ch)
                && ch != '{' && ch != '}'
                && ch != '(' && ch != ')'
                && ch != '[' && ch != ']'
                && ch != ';' && ch != ','
                && ch != '#' && ch != '\\'
                && ch != '\'' && ch != '\"');
    }

    bool ASBase::isDigit(char ch) const {
        return (ch >= '0' && ch <= '9');
    }

    bool ASBase::isDigitSeparator(const string &line, int i) const {
        assert(line[i] == '\'');

        bool foundDigitSeparator = i > 0
                                   && isxdigit((unsigned char) line[i - 1])
                                   && i < (int) line.length() - 1
                                   && isxdigit((unsigned char) line[i + 1]);
        return foundDigitSeparator;
    }

    char ASBase::peekNextChar(const string &line, int i) const {
        char ch = ' ';
        size_t peekNum = line.find_first_not_of(" \t", i + 1);
        if (peekNum == string::npos)
            return ch;
        ch = line[peekNum];
        return ch;
    }

}
