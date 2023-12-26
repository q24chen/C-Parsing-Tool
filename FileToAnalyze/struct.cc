#include "class.hpp"

struct Ast {
    int a;
    char b;
    int *c;
    //std::vector<int> v;
    int add(char e, int d) {
        return e + d;
    }

    int add2(ast a, int b) {
        return a.a + b;
    }
    private:
    int sub(char s) {
        return s - a;
    }
    protected:
    int m() {
        return 0;
    }
};