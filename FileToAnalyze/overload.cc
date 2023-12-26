#include <iostream>

int function(int a, int b, int c) {
    return c;
}

int function(int a, int b) {
    return b;
}

int function(int a) {
    return a;
}

class Vector2D {
public:
    float x, y;

    Vector2D(float x, float y) : x(x), y(y) {}

    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }

    Vector2D operator-(const Vector2D& a, const Vector2D& b) {
         return Vector2D(a.x - b.x, a.y - b.y);
    }
};

Vector2D operator+(const Vector2D& a, const Vector2D& b) {
    return Vector2D(a.x + b.x, a.y + b.y);
}

int main() {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);

    Vector2D v3 = v1 + v2; 
    v3.print();

    return 0;
}
