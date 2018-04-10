#include "cexi/compiler/compiler.h"
#include <iostream>

using namespace std;

int main() {

    Compiler cexi;

    cexi.preprocess("/home/fabian/Documents/repos/datos2/CEX/examples/helloworld.cex");
    cexi.compile();


    return 0;
}
  