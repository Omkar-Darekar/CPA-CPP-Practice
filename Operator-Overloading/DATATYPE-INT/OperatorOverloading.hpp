#ifndef __OPERATOR_OVERLOADING_H__
#define __OPERATOR_OVERLOADING_H__

#include <iostream>

class OperatorOverloading {
    private:
        double iNum;
    public:
        OperatorOverloading(double num);
        void DisplayNumber(char* msg = NULL);

        OperatorOverloading operator+(const OperatorOverloading& other);
        OperatorOverloading operator-(const OperatorOverloading& other);
        OperatorOverloading operator*(const OperatorOverloading& other);
        OperatorOverloading operator/(const OperatorOverloading& other);


};

#endif //__OPERATOR_OVERLOADING_H__