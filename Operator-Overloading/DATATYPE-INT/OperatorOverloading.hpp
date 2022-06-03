#ifndef __OPERATOR_OVERLOADING_H__
#define __OPERATOR_OVERLOADING_H__

#include <iostream>

class OperatorOverloading {
    private:
        int iNum;
    public:
        OperatorOverloading(int num);
        void DisplayNumber(char* msg = NULL);

        OperatorOverloading operator+(const OperatorOverloading& other);
        OperatorOverloading operator-(const OperatorOverloading& other);
        OperatorOverloading operator*(const OperatorOverloading& other);
        OperatorOverloading operator/(const OperatorOverloading& other);
        OperatorOverloading operator%(const OperatorOverloading& other);
        OperatorOverloading operator<<(const int bits);
        OperatorOverloading operator>>(const int bits);

        bool operator==(const OperatorOverloading& other);
        bool operator<(const OperatorOverloading& other);
        bool operator<=(const OperatorOverloading& other);
        bool operator>(const OperatorOverloading& other);
        bool operator>=(const OperatorOverloading& other);
        bool operator!=(const OperatorOverloading& other);


};

#endif //__OPERATOR_OVERLOADING_H__