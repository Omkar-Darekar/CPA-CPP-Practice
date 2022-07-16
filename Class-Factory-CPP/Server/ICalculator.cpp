#include "ICalculator.h"
#include "Calculator.h"

ICalculator* ICalculator::get_instance(int a, int b) {
    return (new calculator(a, b));
}