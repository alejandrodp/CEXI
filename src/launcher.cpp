#include "cexi/interpreter/interpreter.h"
#include <iostream>
# include <regex> 

int main() {

    Interpreter cexi;

    cexi.run("name = getAddr(asdf) ;");

    return 0;
}