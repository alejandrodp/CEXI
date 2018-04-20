# include <string>
# include <regex>
# include <iostream>
# include "interpreter.h"

void Interpreter::run(const std::string& inPutLine){
    using namespace std;

    const string& line = preprocess(inPutLine);

    regex comment ("//.*");

    regex declare_and_assign ("(\\w+) +(\\w+) *= *(.+) *;");
    regex declare ("(\\w+) +(\\w+) *;");
    regex assign ("(\\w+) *= *(.+) *;");

    regex declare_and_assign_int ("int +(\\w+) *= *(\\d+) *;");
    regex declare_int ("int +(\\w+) *;");
    regex assign_int ("(\\w+) *= *(\\d+) *;");

    regex declare_and_assign_char ("char +(\\w+) *= *'(\\w)' *;");
    regex declare_char ("char +(\\w+) *;");
    regex assign_char ("(\\w+) *= *'(\\w)' *;");

    regex declare_and_assign_float ("float +(\\w+) *= *(\\d+.?\\d*) *;");
    regex declare_float ("float +(\\w+) *;");
    regex assign_float ("(\\w+) *= *(\\d+.?\\d*) *;");

    regex declare_and_assign_double ("double +(\\w+) *= *(\\d+.?\\d*) *;");
    regex declare_double ("double +(\\w+) *;");
    regex assign_double ("(\\w+) *= *(\\d+.?\\d*) *;");

    regex declare_and_assign_long ("long +(\\w+) *= *(\\d+) *;");
    regex declare_long ("long +(\\w+) *;");
    regex assign_long ("(\\w+) *= *(\\d+) *;");

    
    
    if(regex_match(line, declare)){
        cout << "Declaration detected" << endl;
        
        smatch match;

        if(regex_search(line.begin(), line.end(), match,  declare_int)){
            cout << "int declaration detected" << endl;

            parse_declaration(match, "int"); 
        
        } else if(regex_search(line.begin(), line.end(), match, declare_char)){
            cout << "char declaration detected" << endl;

            parse_declaration(match, "char"); 

        } else if(regex_search(line.begin(), line.end(), match, declare_float)){
            cout << "float declaration detected" << endl;

            parse_declaration(match, "float"); 

        } else if(regex_search(line.begin(), line.end(), match, declare_double)){
            cout << "double declaration detected" << endl;

            parse_declaration(match, "double"); 

        } else if(regex_search(line.begin(), line.end(), match, declare_long)){
            cout << "long declaration detected" << endl;

            parse_declaration(match, "long");           
            
        } else{
            cout << "Syntax error." << endl;
        }

    } else if (regex_match(line, declare_and_assign)){
        cout << "Declaration and assignation detected" << endl;

        smatch match;

        if(regex_search(line.begin(), line.end(), match, declare_and_assign_int)){
            cout << "int declaration and assignation detected" << endl;

            parse_declaration_and_asignation(match, "int");
        
        } else if(regex_search(line.begin(), line.end(), match, declare_and_assign_char)){
            cout << "char declaration and assignation detected" << endl;

            parse_declaration_and_asignation(match, "char");

        } else if(regex_search(line.begin(), line.end(), match, declare_and_assign_float)){
            cout << "float declaration and assignation detected" << endl;

            parse_declaration_and_asignation(match, "float");

        } else if(regex_search(line.begin(), line.end(), match, declare_and_assign_double)){
            cout << "double declaration and assignation detected" << endl;

            parse_declaration_and_asignation(match, "double");

        } else if(regex_search(line.begin(), line.end(), match, declare_and_assign_long)){
            cout << "long declaration and assignation detected" << endl;

            parse_declaration_and_asignation(match, "long");
            
        } else{
            cout << "Syntax error." << endl;
        }

    } else if (regex_match(line, assign)){
        cout << "Assignation detected" << endl;

        smatch match;

        if(regex_search(line.begin(), line.end(), match, assign_int)){
            cout << "int assignation detected" << endl;

            parse_asignation(match, "int");
        
        } else if(regex_search(line.begin(), line.end(), match, assign_char)){
            cout << "char assignation detected" << endl;

            parse_asignation(match, "char");

        } else if(regex_search(line.begin(), line.end(), match, assign_float)){
            cout << "float assignation detected" << endl;

            parse_asignation(match, "float");

        } else if(regex_search(line.begin(), line.end(), match, assign_double)){
            cout << "double assignation detected" << endl;

            parse_asignation(match, "double");

        } else if(regex_search(line.begin(), line.end(), match, assign_long)){
            cout << "long assignation detected" << endl;

            parse_asignation(match, "long");
            
        } else{
            cout << "Syntax error" << endl;
        }

    } else if (regex_match(line, comment)){
        cout << "Comment detected" << endl;
        return;

    } else {
        cout << "Syntax error" << endl;
        return;
    }
}

void Interpreter::parse_declaration(std::smatch match, std::string type){
    using namespace std;

    string name = match[1];

    cout << "\tname: " << name << endl;

}

void Interpreter::parse_declaration_and_asignation(std::smatch match, std::string type){
    using namespace std;

    string name = match[1];
    string value = match[2];

    cout << "\tname: " << name << endl;
    cout << "\tvalue: " << value << endl;
    
}
void Interpreter::parse_asignation(std::smatch match, std::string type){
    using namespace std;

    string name = match[1];
    string newValue = match[2];

    cout << "\tname: " << name << endl;
    cout << "\tnew value: " << newValue << endl;
    
}

std::string Interpreter::preprocess(std::string code){
    
    code = reduce(code);

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


//todo: no dejar al usuario usar como nombre para las variables palabras reservadas