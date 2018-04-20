#include "cexi/interpreter/interpreter.h"
#include <iostream>
# include <regex> 

int main() {

    Interpreter cexi;

    cexi.run("//    int =   5;         ");

    return 0;
}