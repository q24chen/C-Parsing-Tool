#include <iostream>
#include <string>

typedef std::string StringAlias;

using IntegerAlias = int;

void displayValues(const StringAlias& str, IntegerAlias num) {
    std::cout << "String: " << str << "\n";
    std::cout << "Integer: " << num << std::endl;
}

int main() {
    StringAlias myString = "Hello, world!";
    IntegerAlias myNumber = 42;

    displayValues(myString, myNumber);

    return 0;
}