#ifndef CALCULATOR
#define CALCULATOR

#include <iostream>
#include <string>

class Calculator {
public:
    double add(double a, double b);
    double sub(double a, double b);
    double mul(double a, double b);
    double div(double a, double b);
    
    int mod(int a, int b);
    
    bool andd(bool a, bool b);
    bool orr(bool a, bool b);
    bool nott(bool a);

    bool gt(double a, double b);
    bool gte(double a, double b);

    bool lt(double a, double b);
    bool lte(double a, double b);

    
    
};


#endif