# include <string>
# include <regex>
# include <iostream>
# include <sstream>
# include <fstream>
# include <iterator>


std::string *preprocessor(std::string path){
    using namespace std;

    ifstream source_file (path);

    string source_file_as_string (istreambuf_iterator<char>{source_file}, {});

    regex ppe_new_line ("\n+");
    regex ppe_white_space (" +");
    regex ppe_tab ("\t+");
    regex ppe_comment ("//.+\n");

    auto *temp = new string;
    *temp = regex_replace (source_file_as_string , ppe_comment , " ");
    *temp = regex_replace (*temp , ppe_new_line , "");
    *temp = regex_replace (*temp , ppe_white_space , " ");
    *temp =  regex_replace (*temp , ppe_tab , " ");

    cout << "File processed: " << *temp << endl;

    return temp;
}