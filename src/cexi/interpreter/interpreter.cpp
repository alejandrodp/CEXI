# include <string>
# include <regex>
# include <iostream>
# include <sstream>
# include <fstream>
# include <iterator>
# include "interpreter.h"
# include <iostream>
# include <string>

/**
 * agarrar linea
 * eliminar whitespace innecesario
 * puede ser:
 *      delcaracion
 *      asignacion
 *      operacion
 *      scope
 * identificar cual es
 * ejecutar la picha esta
 * 
 * 
 */

void Interpreter::run(std::string path){
    using namespace std;

    ifstream source_file (path);
    string code (istreambuf_iterator<char>{source_file}, {});

    code = preprocess(code);

    





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
    using namespace std;
    
    regex ppe_white_space ("\s+");

    code = regex_replace (code , ppe_white_space , " ");

    cout << "Line: " << code << endl;

    return code;
}

