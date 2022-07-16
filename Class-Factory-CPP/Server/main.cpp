#include "Calculator.h"

int main() {
    calculator* obj = new calculator(10, 12);

    int ret;
    obj->add(10, 20, &ret);
    obj->show();

    return (0);
}