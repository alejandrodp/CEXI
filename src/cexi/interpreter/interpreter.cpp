# include <string>
# include <regex>
# include <iostream>
# include <sstream>
# include <fstream>
# include <iterator>
# include "interpreter.h"
# include <iostream>
# include <string>

void Interpreter::run(std::string inPutLine){
    using namespace std;

    auto line = preprocess(inPutLine);

    regex declare_and_assign ("(\\w+) (\\w+) *= *(.+) *;");
    regex declare ("(\\w+) (\\w+) *;");

    regex declare_and_assign_int ("int (\\w+) *= *(\\d+) *;");
    regex declare_int ("int (\\w+) *;");

    regex declare_and_assign_char ("char (\\w+) *= *'(\\w)' *;");
    regex declare_char ("char (\\w+) *;");

    regex declare_and_assign_float ("float (\\w+) *= *(\\d+.?\\d*) *;");
    regex declare_float ("float (\\w+) *;");

    regex declare_and_assign_double ("double (\\w+) *= *(\\d+.?\\d*) *;");
    regex declare_double ("double (\\w+) *;");

    regex declare_and_assign_long ("long (\\w+) *= *(\\d+) *;");
    regex declare_long ("long (\\w+) *;");
    
    if(regex_match(line, declare)){
        cout << "Declaration detected" << endl;

        if(regex_match(line, declare_int)){
            cout << "int declaration detected" << endl;
        
        }else if(regex_match(line, declare_char)){
            cout << "char declaration detected" << endl;

        }else if(regex_match(line, declare_float)){
            cout << "float declaration detected" << endl;

        }else if(regex_match(line, declare_double)){
            cout << "double declaration detected" << endl;

        }else if(regex_match(line, declare_long)){
            cout << "long declaration detected" << endl;
            
        }else{
            cout << "Syntax error." << endl;
        }

    } else if (regex_match(line, declare_and_assign)){
        cout << "Declaration and assignation detected" << endl;

        if(regex_match(line, declare_and_assign_int)){
            cout << "int declaration and assignation detected" << endl; 
        
        }else if(regex_match(line, declare_and_assign_char)){
            cout << "char declaration and assignation detected" << endl;

        }else if(regex_match(line, declare_and_assign_float)){
            cout << "float declaration and assignation detected" << endl;

        }else if(regex_match(line, declare_and_assign_double)){
            cout << "double declaration and assignation detected" << endl;

        }else if(regex_match(line, declare_and_assign_long)){
            cout << "long declaration and assignation detected" << endl;
            
        }else{
            cout << "Syntax error." << endl;
        }

    }
}

/*
std::string Interpreter::getNextLine(std::string text){
    using namespace std;

    smatch match;
    regex ppe_white_space ("\n(.*)");
    
    if(regex_search(text, match, ppe_white_space)){
        for (auto x : match) std::cout << x << " ";
            std::cout << std::endl;
            text = match.suffix().str();
    }
    

}
*/

void Interpreter::interpret(std::string statement){

}

void Interpreter::readLine(std::string line){
    //if(contains(line, "int "))

}

bool Interpreter::contains(std::string text, std::string substring){
    return text.find(substring) != std::string::npos;
}

std::string Interpreter::preprocess(std::string code){
    
    code = reduce(code);

    std::cout << code << std::endl;

    return code;
}


std::string Interpreter::trim(const std::string& str, const std::string& whitespace){
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

std::string Interpreter::reduce(const std::string& str,
                   const std::string& fill,
                   const std::string& whitespace){
    // trim first
    auto result = trim(str, whitespace);

    // replace sub ranges
    auto beginSpace = result.find_first_of(whitespace);
    while (beginSpace != std::string::npos)
    {
        const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
        const auto range = endSpace - beginSpace;

        result.replace(beginSpace, range, fill);

        const auto newStart = beginSpace + fill.length();
        beginSpace = result.find_first_of(whitespace, newStart);
    }

    return result;
}