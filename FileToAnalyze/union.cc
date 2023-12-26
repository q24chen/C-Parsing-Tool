#include <iostream>

union MyUnion {
    int myInt;    
    double myDouble;  

    struct {
        int low : 16; 
        int high : 16; 
    } myBits;

    void setInt(int i) {
        myInt = i;
    }

    int getInt() const {
        return myInt;
    }

    void display() const {
        std::cout << "Int: " << myInt << ", Double: " << myDouble << std::endl;
    }
}; 

int main() {
    MyUnion u;
    u.setInt(1024);
    u.display();
    u.myDouble = 3.14;
    u.display(); // Note that setting myDouble overwrites myInt

    return 0;
}
