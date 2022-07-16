#include "ICalculator.h"
#include <iostream>
int main() {
    ICalculator* p = 0;
    p = ICalculator::get_instance(10, 20);
    p->show();
    int a;
    p->add(20, 30, &a);
    std::cout << "a : " << a << std::endl;
    return (0);
}