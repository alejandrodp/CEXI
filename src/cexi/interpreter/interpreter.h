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

    /**
     * @brief parses a declaration and an asignation
     * 
     * @param match regex match
     * @param type type of declaration
     */
    static void parse_declaration_and_asignation(std::smatch match, std::string type);

    /**
     * @brief parses a declaration
     * 
     * @param match regex match
     * @param type type of declaration
     */
    static void parse_declaration(std::smatch match, std::string type);

    /**
     * @brief parses an asignation
     * 
     * @param match regex match
     * @param type type of declaration
     */
    static void parse_asignation(std::smatch match, std::string type);

    /**
     * @brief parses a reference declaration
     * 
     * @param match regex match
     * @param type type of declaration
     */
    static void parse_reference_declaration(std::smatch match, std::string type);

    /**
     * @brief parses a declaration and an asignation
     * 
     * @param match regex match
     * @param type type of declaration
     */
    static void parse_reference_declaration_and_assignation(std::smatch match, std::string type);

    /**
     * @brief parses a reference declaration and an asignation
     * 
     * @param match regex match
     * @param type type of declaration
     */
    static void parse_reference_assignation(std::smatch match);

    /**
     * @brief removes whitespace
     * 
     * @param str string to be modified
     * @param fill replacement for extra-whitespace
     * @param whitespace definition of whitespace
     * @return std::string modified string
     */
    static std::string reduce(const std::string& str,
                   const std::string& fill = " ",
                   const std::string& whitespace = " \t");

    /**
     * @brief removes whitespace from edges
     * 
     * @param str string to be modified
     * @param whitespace definition of whitespace
     * @return std::string modified string
     */
    static std::string trim(const std::string& str, const std::string& whitespace = " \t");

    



};

#endif