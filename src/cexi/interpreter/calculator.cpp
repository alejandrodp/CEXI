#include "calculator.h"

double Calculator::add(double a, double b){return a+b;}
double Calculator::sub(double a, double b){return a-b;}
double Calculator::mul(double a, double b){return a*b;}
double Calculator::div(double a, double b){return a/b;}

int Calculator::mod(int a, int b){return a%b;}

bool Calculator::andd(bool a, bool b){return a and b;}
bool Calculator::orr(bool a, bool b){return a or b;}
bool Calculator::nott(bool a){return !a;}

bool Calculator::gt(double a, double b){return a>b;}