
#ifndef __ICALCULATOR_H__
#define __ICALCULATOR_H__

class ICalculator {
    public:
        virtual void add(int x, int y, int* ret) = 0;
        virtual void show() = 0;
        static ICalculator* get_instance(int a, int b);
};

#endif //__ICALCULATOR_H__

