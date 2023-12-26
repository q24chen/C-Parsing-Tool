#include <iostream>

// Base enum
enum class Color : char {
    Red,
    Green,
    Blue
};

class ExampleClass {
public:
    void changeColor(Color newColor) {
        color = newColor;
    }

    void displayColor() const {
        std::cout << "Current color: ";
        switch (color) {
            case Color::Red:
                std::cout << "Red";
                break;
            case Color::Green:
                std::cout << "Green";
                break;
            case Color::Blue:
                std::cout << "Blue";
                break;
        }
        std::cout << std::endl;
    }

private:
    Color color = Color::Red; 
};

int main() {
    ExampleClass obj;
    obj.displayColor(); 

    obj.changeColor(Color::Green);
    obj.displayColor(); 

    return 0;
}
