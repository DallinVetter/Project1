#include "IDAutomaton.h"
void IDAutomaton::S0(const std::string &input) {
    if (((input.substr(0,5) == "Facts") && isspace(input[5])) || ((input.substr(0,7) == "Schemes") && isspace(input[7]))
    || ((input.substr(0,5) == "Rules") && isspace(input[5])) || ((input.substr(0,7) == "Queries" && isspace(input[7])))){
        Serr();
    }
    else if (isalpha(input.at(0))) {
        inputRead++;
        index++;
        S1(input);
    }
    else{
        Serr();
    }
}

void IDAutomaton::S1(const std::string &input) {
    if (isalpha(input[index]) || isdigit(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else if(isspace(input[index]) || input[index] == '\n' || index >= input.size()){
    }

    else{
        //Serr();
    }
}
