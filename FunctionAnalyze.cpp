#include <iostream>
#include <clang-c/Index.h>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

std::map<std::string, std::vector<std::string>> namespaceFunctions;
std::map<std::string, std::vector<std::string>> publicMethods;

std::string getFunctionParameters(CXCursor cursor) {
    std::string result;

    int numTemplateArgs = clang_Cursor_getNumTemplateArguments(cursor);
    if (numTemplateArgs > 0) {
        result += "<";
        for (int i = 0; i < numTemplateArgs; i++) {
            if (i > 0) {
                result += ", ";
            }
            CXType argType = clang_Cursor_getTemplateArgumentType(cursor, i);
        }
        result += ">";
    }

    CXType functionType = clang_getCursorType(cursor);
    int numArgs = clang_getNumArgTypes(functionType);
    if (numArgs == -1) {
        // This might be a function template without defined parameters, or an invalid cursor type
        return result + "(...)";
    }

    result += "(";
    for (int i = 0; i < numArgs; i++) {
        if (i > 0) {
            result += ", ";
        }
        CXType argType = clang_getArgType(functionType, i);
        result += clang_getCString(clang_getTypeSpelling(argType));
    }
    result += ")";

    return result;
}


enum CXChildVisitResult visitor(CXCursor cursor, CXCursor /*parent*/, CXClientData client_data) {
    CXSourceLocation location = clang_getCursorLocation(cursor);
    if (clang_Location_isInSystemHeader(location)) {
        return CXChildVisit_Continue;
    }

    CXCursorKind kind = clang_getCursorKind(cursor);

    if (kind == CXCursor_Namespace) {
        std::string namespaceName = clang_getCString(clang_getCursorSpelling(cursor));
        clang_visitChildren(cursor, visitor, &namespaceName);
    } else if (kind == CXCursor_FunctionDecl || kind == CXCursor_FunctionTemplate) {
        std::string functionName = clang_getCString(clang_getCursorSpelling(cursor)) + getFunctionParameters(cursor);
        if (client_data) {
            std::string* currentNamespace = static_cast<std::string*>(client_data);
            namespaceFunctions[*currentNamespace].push_back(functionName);
        } else {
            namespaceFunctions["global"].push_back(functionName);
        }
    } else if (kind == CXCursor_CXXMethod) {
        CX_CXXAccessSpecifier access = clang_getCXXAccessSpecifier(cursor);
        if (access == CX_CXXPublic) {
            std::string className = clang_getCString(clang_getCursorSpelling(clang_getCursorSemanticParent(cursor)));
            publicMethods[className].push_back(clang_getCString(clang_getCursorSpelling(cursor)) + getFunctionParameters(cursor));
        }
    }

    return CXChildVisit_Recurse;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file.cpp>" << std::endl;
        return 1;
    }

    CXIndex index = clang_createIndex(0, 0);
    CXTranslationUnit unit = clang_parseTranslationUnit(index, argv[1], nullptr, 0, nullptr, 0, CXTranslationUnit_None);
    if (unit == nullptr) {
        std::cerr << "Unable to parse translation unit. Quitting." << std::endl;
        return -1;
    }

    clang_visitChildren(clang_getTranslationUnitCursor(unit), visitor, nullptr);

    // Cleanup step: Remove duplicates from the "global" namespace
    if (namespaceFunctions.find("global") != namespaceFunctions.end()) {
        auto& globalFunctions = namespaceFunctions["global"];
        globalFunctions.erase(std::remove_if(globalFunctions.begin(), globalFunctions.end(),
                                             [&](const std::string& func) {
                                                 for (const auto& ns : namespaceFunctions) {
                                                     if (ns.first != "global" && std::find(ns.second.begin(), ns.second.end(), func) != ns.second.end()) {
                                                         return true;  // Remove if function is found in any other namespace
                                                     }
                                                 }
                                                 return false;
                                             }),
                              globalFunctions.end());
    }

    for (auto& ns : namespaceFunctions) {
        auto& functions = ns.second;
        std::sort(functions.begin(), functions.end());
        auto last = std::unique(functions.begin(), functions.end());
        functions.erase(last, functions.end());
    }

    for (auto& cls : publicMethods) {
        auto& methods = cls.second;
        std::sort(methods.begin(), methods.end());
        auto last = std::unique(methods.begin(), methods.end());
        methods.erase(last, methods.end());
    }

    for (const auto& ns : namespaceFunctions) {
        std::cout << ns.first << ":\n";
        for (const auto& func : ns.second) {
            std::cout << func << std::endl;
        }
        std::cout << "\n--------------------------------------\n";
    }

    std::cout << "public functions:\n";
    for (const auto& pair : publicMethods) {
        std::cout << pair.first << ":\n";
        for (const auto& method : pair.second) {
            std::cout << method << std::endl;
        }
        std::cout << "\n--------------------------------------\n";
    }

    clang_disposeTranslationUnit(unit);
    clang_disposeIndex(index);

    return 0;
}

