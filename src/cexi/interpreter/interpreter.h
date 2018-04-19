#ifndef INTERPRETER
#define INTERPRETER

#include <iostream>
#include <string>

class Interpreter {
public:

    /**
     * @brief runs the code
     * 
     * @param path path to code
     */
    void run(std::string path);

    /**
     * @brief interprets a single line of code
     * 
     * @param statement 
     */
    void interpret(std::string statement);

    /**
     * @brief reads a line
     * 
     * @param line line to be read
     */
    void readLine(std::string line);

    /**
     * @brief 
     * 
     */
    bool contains(std::string text, std::string substring);

    /**
     * @brief cleans the code
     * 
     * @param code code to be cleaned
     * @return std::string cleaned code
     */
    std::string preprocess(std::string code);

    std::string reduce(const std::string& str,
                   const std::string& fill = " ",
                   const std::string& whitespace = " \t");

    std::string trim(const std::string& str, const std::string& whitespace = " \t");

    



};

#endif