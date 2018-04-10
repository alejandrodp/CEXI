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
    std::string preprocess(std::string path);
    
    /**
     * @brief Takes pre-processed text and generates a byte-code file.
     * 
     * @param processed_code string with pre-processed text
     */
    void compile(std::string processed_code);

    /**
     * @brief Saves byte code to a temporary file.
     * 
     * @param byteCode byte code to save
     */
    void saveByteCode(std::string byteCode);
	

};



#endif