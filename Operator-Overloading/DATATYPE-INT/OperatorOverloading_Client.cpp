#include "OperatorOverloading.hpp"

int main(void) {
    OperatorOverloading obj1(100);
    OperatorOverloading obj2(20);

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
    
    obj3 = obj1 % obj2;
    obj3.DisplayNumber();

    obj3 = obj1 << 3;
    obj3.DisplayNumber();

    obj3 = obj1 >> 3;
    obj3.DisplayNumber();

    std::cout << "obj1 == obj2 : " << (obj1 == obj2) << std::endl;
    std::cout << "obj1 < obj2 : " << (obj1 < obj2) << std::endl;
    std::cout << "obj1 <= obj2 : " << (obj1 <= obj2) << std::endl;
    std::cout << "obj1 > obj2 : " << (obj1 > obj2) << std::endl;
    std::cout << "obj1 >= obj2 : " << (obj1 >= obj2) << std::endl;
    std::cout << "obj1 != obj2 : " << (obj1 != obj2) << std::endl;

    return (0);
}