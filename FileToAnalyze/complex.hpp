#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include <vector>
#include <map>
#include <string>

namespace MyNamespace {

// Declarations of class, struct, union, and enum
class MyClass {
public:
    MyClass() = default;
    virtual void virtualFunction() const;
    void publicFunction(int value) {}

private:
    int privateVar;
};

struct MyStruct {
    int member;
};

union MyUnion {
    int intMember;
    char charMember;
};

enum class MyEnum : int {
    First,
    Second
};

// Type with decoration of typedef or using
typedef std::vector<int> IntVector;
using StringMap = std::map<std::string, std::string>;

// Global Variables
int globalInt;
bool globalBool;
std::vector<double> globalVector;
std::map<std::string, int> globalMap;
MyClass globalMyClass;
MyStruct globalMyStruct;

// Function Declarations
void functionUsingNativeTypes(int param1, bool param2) {}
void functionUsingStdLibraryTypes(const IntVector& vec, const StringMap& map) {}
void functionUsingUserDefinedTypes(const MyClass& myClass, const MyStruct& myStruct, MyEnum myEnum) {}
void functionUsingUnion(const MyUnion& myUnion) {}
void functionUsingGlobalVariables() {
    int localVar = globalInt;
    bool localBool = globalBool;
    std::vector<double> localVector = globalVector;
    std::map<std::string, int> localMap = globalMap;
    MyClass localMyClass = globalMyClass;
    MyStruct localMyStruct = globalMyStruct;
}

// Function Overloading
void overloadedFunction(int param) {}
void overloadedFunction(double param) {}

// Global Operator Overloading
bool operator==(const MyStruct& lhs, const MyStruct& rhs) { return lhs.member == rhs.member; }

// Class Polymorphism - Inheritance
class DerivedClass : public MyClass {
public:
    void virtualFunction() const override {}
};

// Union with Member and Bitwise Member Declarations
union BitwiseUnion {
    int intMember;
    struct {
        unsigned int bit1 : 1;
        unsigned int bit2 : 1;
        unsigned int bit3 : 1;
    } bits;
};

void unionFunction(const MyUnion& u) {}

} // namespace MyNamespace

#endif 
