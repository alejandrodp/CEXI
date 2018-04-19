#include "cexi/interpreter/interpreter.h"
#include <iostream>
# include <regex> 

int main() {

    Interpreter cexi;

    cexi.run("    float    a =               1.3  ;         ");

    return 0;
}