#include <iostream>
#include <memory>

class Base {
public:
    virtual ~Base() {}

    virtual void display() const {
        std::cout << "Base class display" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() const override {
        std::cout << "Derived class display" << std::endl;
    }
};

void processObject(const std::unique_ptr<Base>& obj) {
    obj->display();
}

int main() {
    std::unique_ptr<Base> base = std::make_unique<Base>();
    std::unique_ptr<Base> derived = std::make_unique<Derived>();

    processObject(base);    
    processObject(derived); 

    return 0;
}
