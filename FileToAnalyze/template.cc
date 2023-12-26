//#include <iostream>

template<typename T> T maximummmmmmmm(T a, T b) {
    return a < b? a : b;
}

class T{
public: 
    template<typename T> T min(T a, int b, T c) {
        return a > b? a : b;
    }
};


int main() {
    int a = 3;
    int b = 4;
    int c = maximummmmmmmm(a, b);
    //std::cout << c << std::endl;
    return 1;
}


