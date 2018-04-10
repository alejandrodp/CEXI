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
<<<<<<< HEAD
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



=======
    std::string * preprocessor(std::string path);


};
>>>>>>> 5b4cddb191eb5afed8e9f70a6b90c06f2f4d4faa
#endif