# include <string>
# include <regex>
# include <iostream>
# include <sstream>
# include <fstream>
# include <iterator>



int main() {

    std::ifstream file("/home/fabian/Documents/repos/datos2/CEX/examples/helloworld.cex");

    std::string str(std::istreambuf_iterator<char>{file}, {});

    std::cout << str ;
    /*
    std::string nigger ("there is a subsequence in the string\n");
    std::regex e ("\\b(sub)([^ ]*)");   // matches words beginning by "sub"

    std::cout << std::regex_replace (nigger,e,"sub-$2");
    */
    return 0;
}