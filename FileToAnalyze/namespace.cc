#include <iostream>


namespace MyNamespace1 {
    void namespaceFunction1() {
        std::cout << "Hello from MyNamespace1!" << std::endl;
    }

    void namespaceFunction2() {
        std::cout << "Hello from MyNamespace2!" << std::endl;
    }
}

namespace MyNamespaceA {
    void namespaceFunctionA() {
        std::cout << "Hello from MyNamespaceA!" << std::endl;
    }

    void namespaceFunctionB() {
        std::cout << "Hello from MyNamespaceB!" << std::endl;
    }
}

void globalFunction() {
    std::cout << "Hello from global scope!" << std::endl;
}

int main() {

    //globalFunction();
    //MyNamespace::namespaceFunction();

    return 0;
}