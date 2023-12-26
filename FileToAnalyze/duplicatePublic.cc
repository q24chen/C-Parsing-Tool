#include <iostream>
#include <string>

class ExampleClass {
public:
    ExampleClass(const std::string& name);

    void displayMessage() const;

private:
    std::string name;
};

ExampleClass::ExampleClass(const std::string& name) : name(name) {}

void ExampleClass::displayMessage() const {
    std::cout << "Hello, " << name << "!" << std::endl;
}

int main() {
    ExampleClass example("Test");
    example.displayMessage();
    return 0;
}