#include "cexi/interpreter/interpreter.h"
#include <iostream>
# include <regex> 

int main() {

    Interpreter cexi;

    cexi.run(" int a ;         ");

    return 0;
}