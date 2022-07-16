

#ifndef __CALULATO_H__
#define __CALULATO_H__
#include <iostream>
#include "ICalculator.h"



class calculator : public ICalculator{
    private:
        int a;
        int b;
    public:
        calculator(int _a, int _b);
        void add(int x, int y, int* ret);
        void show();
};

class A : public calculator {
    
};

#endif //__CALULATO_H__