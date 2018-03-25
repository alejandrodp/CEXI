#ifndef COMPILER
#define COMPILER

#include <iostream>
#include <string>

class Compiler {
public:

    /**
     * @brief Takes a file and returns a cleaned string of its contents.
     * 
     * @param path path of the file to process
     * @return std::string* pointer of the clean string
     */
    std::string * preprocessor(std::string path);


};
#endif