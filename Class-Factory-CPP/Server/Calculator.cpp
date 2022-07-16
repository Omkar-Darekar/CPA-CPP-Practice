
#include "Calculator.h"

calculator::calculator(int _a, int _b) : a(_a), b(_b) {

}

void calculator::add(int x, int y, int* ret) {
    *ret = x+y;
}

void calculator::show() {
    std::cout << "a : " << a <<"\tb : " << b << std::endl;
}


