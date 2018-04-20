#include "cexi/interpreter/interpreter.h"
#include <iostream>
# include <regex> 

int main() {

    Interpreter cexi;

    cexi.run("    int    a = 2;         ");

    return 0;
}