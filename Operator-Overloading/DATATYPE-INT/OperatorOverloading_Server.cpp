#include "OperatorOverloading.hpp"

OperatorOverloading::OperatorOverloading(double num = 0.00) : iNum(num) {

}

void OperatorOverloading::DisplayNumber(char* msg) {
    if(msg)
        printf("%s", msg);
    std::cout << "iNum : " << iNum << std::endl;
}

OperatorOverloading OperatorOverloading::operator+(const OperatorOverloading& other) {
    return (OperatorOverloading(this->iNum + other.iNum));
}

OperatorOverloading OperatorOverloading::operator-(const OperatorOverloading& other) {
    return (OperatorOverloading(this->iNum - other.iNum));
}

OperatorOverloading OperatorOverloading::operator*(const OperatorOverloading& other) {
    return (OperatorOverloading(this->iNum * other.iNum));
}

OperatorOverloading OperatorOverloading::operator/(const OperatorOverloading& other) {
    return (OperatorOverloading(this->iNum / other.iNum));
}

