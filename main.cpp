#include <iostream>
#include <regex>
#include <fstream>
#include <vector>

using std::ifstream;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
    std::cout << "Hello, World!" << std::endl;

    /* // Testing for regex
    std::string testString ("16:06:50 From Uddeep Karki To Everyone : https://docs.google.com/document/d/1NWWOHJX0iZLlten06qih0a34ebtnQklvt25u7DjQens/edit?usp=sharing");

    std::regex base_regex(".*:.*:.*:\\s(.*)");
    std::smatch base_match;
    std::regex_match( testString, base_match, base_regex);

    cout << base_match.size() << endl;

    cout << base_match[1].str() << endl; //because [0] is whole string match
    */
    ifstream myFile;
    myFile.open("chatlog.txt");

    if(myFile.fail() || myFile.bad()) {
        cout << "Check file location, and name. Ensure chat log file name is chatlog.txt" << endl;
        return 1;
    }
    string messageLine;
    vector <string> contentsOfTheMessages;

    while ( getline(myFile, messageLine)) {
        std::regex base_regex(".*:.*:.*:\\s(.*)");
        std::smatch base_match;

        std::regex_match( messageLine, base_match, base_regex);

        cout << base_match.size() << endl;

        //cout << base_match[1].str() << endl; //because [0] is whole string match
        //Instead we are pushing back to the vector contentsOfTheMessages

        contentsOfTheMessages.push_back( base_match[1].str());
    }
    myFile.close();

    //Create output file stream.

    std::ofstream myOutFile ( "myMessages.txt" , std::ofstream::out);

    for ( const auto &a : contentsOfTheMessages) {
        myOutFile << a << endl;
    }

    myOutFile.close();


    return 0;
}

