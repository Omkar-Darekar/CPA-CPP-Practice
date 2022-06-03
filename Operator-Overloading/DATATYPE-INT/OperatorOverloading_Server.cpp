#include "OperatorOverloading.hpp"

OperatorOverloading::OperatorOverloading(int num = 0) : iNum(num) {

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

OperatorOverloading OperatorOverloading::operator%(const OperatorOverloading& other) {
    return (OperatorOverloading(this->iNum % other.iNum));
}

OperatorOverloading OperatorOverloading::operator<<(const int bits) {
    return (OperatorOverloading(this->iNum << bits));
}

OperatorOverloading OperatorOverloading::operator>>(const int bits) {
    return (OperatorOverloading(this->iNum >> bits));
}

bool OperatorOverloading::operator==(const OperatorOverloading& other) {
    return (this->iNum == other.iNum);
}

bool OperatorOverloading::operator<(const OperatorOverloading& other) {
    return (this->iNum < other.iNum);
}

bool OperatorOverloading::operator<=(const OperatorOverloading& other) {
    return (this->iNum <= other.iNum);
}

bool OperatorOverloading::operator>(const OperatorOverloading& other) {
    return (this->iNum > other.iNum);
}

bool OperatorOverloading::operator>=(const OperatorOverloading& other) {
    return (this->iNum >= other.iNum);
}

bool OperatorOverloading::operator!=(const OperatorOverloading& other) {
    return (this->iNum != other.iNum);
}

