#ifndef INTERPRETER
#define INTERPRETER

# include <string>
# include <regex>
# include <iostream>

class Interpreter {
public:

    /**
     * @brief runs the code
     * 
     * @param path path to code
     */
    void run(const std::string& inPutLine);

    /**
     * @brief cleans the code
     * 
     * @param code code to be cleaned
     * @return std::string cleaned code
     */
    std::string preprocess(std::string code);

    void parse_declaration_and_asignation(std::smatch match, std::string type);

    void parse_declaration(std::smatch match, std::string type);

    void parse_asignation(std::smatch match, std::string type);

    std::string reduce(const std::string& str,
                   const std::string& fill = " ",
                   const std::string& whitespace = " \t");

    std::string trim(const std::string& str, const std::string& whitespace = " \t");

    



};

#endif