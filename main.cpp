#include<iostream>
#include <fstream>
#include <sstream>
#include "Lexer.h"
using namespace std;

int main(int argc, char** argv) {

    // open file
    string fileName = argv[1];
    ifstream input(fileName);
    if (!input.is_open()) {
        cout << "File " << fileName << " could not be found or opened." << endl;
        return 1;
    }
    string text;
    stringstream streamer;
    streamer << input.rdbuf();
    text = streamer.str();
    Lexer* lexer = new Lexer();
    lexer->Run(text);

    // TODO

    //delete lexer;

    return 0;
}