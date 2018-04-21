#ifndef INTERPRETER
#define INTERPRETER

# include <string>
# include <regex>
# include <iostream>

class Interpreter {
public:

    Interpreter(){}

    /**
     * @brief runs the code
     * 
     * @param path path to code
     */
    static void run(const std::string& inPutLine);

    /**
     * @brief cleans the code
     * 
     * @param code code to be cleaned
     * @return std::string cleaned code
     */
    static std::string preprocess(std::string code);

    static void parse_declaration_and_asignation(std::smatch match, std::string type);

    static void parse_declaration(std::smatch match, std::string type);

    static void parse_asignation(std::smatch match, std::string type);

    static std::string reduce(const std::string& str,
                   const std::string& fill = " ",
                   const std::string& whitespace = " \t");

    static std::string trim(const std::string& str, const std::string& whitespace = " \t");

    



};

#endif