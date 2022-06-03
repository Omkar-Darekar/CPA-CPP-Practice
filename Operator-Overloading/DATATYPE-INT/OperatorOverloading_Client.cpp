#include "OperatorOverloading.hpp"

int main(void) {
    OperatorOverloading obj1(100.00);
    OperatorOverloading obj2(20.00);

    obj1.DisplayNumber("Obj1 : ");
    obj2.DisplayNumber();

    OperatorOverloading obj3 = obj1 + obj2;
    obj3.DisplayNumber();

    obj3 = obj1 - obj2;
    obj3.DisplayNumber();

    obj3 = obj1 * obj2;
    obj3.DisplayNumber();

    obj3 = obj1 / obj2;
    obj3.DisplayNumber();
    

    return (0);
}