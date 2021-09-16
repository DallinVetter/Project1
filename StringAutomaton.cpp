#include "StringAutomaton.h"
void StringAutomaton::S0(const std::string& input) {
    commaCounter = 0;
    if (index >= input.size()) {
        Serr();
    }
    else if (input[index] == '\'') {
        inputRead++;
        index++;
        commaCounter++;
        S1(input);
    }
    else{
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input) {
    if (index >= input.size()){
        setTokenType(TokenType::UNDEFINED);
    }

    else if(input[index] == '\n') {
        newLines++;
        index++;
        inputRead++;
        S1(input);
    }

    else if (input[index] != '\''){
        inputRead++;
        index++;
        S1(input);
    }

    else if (input[index] == '\''){
        inputRead++;
        index++;
        commaCounter++;
        S2(input);
    }
    else{
        Serr();
    }
}
void StringAutomaton::S2(const std::string& input) {
    if (index >= input.size()){
        setTokenType(TokenType::UNDEFINED);
    }
    else if (input[index] != '\''){
    }

    else if (input[index] == '\''){
        inputRead++;
        index++;
        commaCounter++;
        S1(input);
    }
}