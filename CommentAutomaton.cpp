#include "CommentAutomaton.h"
void CommentAutomaton::S0(const std::string &input) {
    if (index >= input.size()) {
        Serr();
    }
    else if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else{
        Serr();
    }
}

void CommentAutomaton::S1(const std::string &input) {
    if (index > input.size()){}

    else if ((input[index] == '|') && (input[index-1] == '#')) {
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == '\n') {

    }
    else {
        inputRead++;
        index++;
        S1(input);
    }
}
void CommentAutomaton::S2a(const std::string &input) {
    if (index > input.size()){}

    else if (input[index] == '\n') {

    }
    else {
        inputRead++;
        index++;
        S2a(input);
    }
}
void CommentAutomaton::S2(const std::string &input) {
    if (index >= input.size()){
        setTokenType(TokenType::UNDEFINED);
    }
    else if (input[index] == '\n') {
        newLines++;
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == '|') {
        inputRead++;
        index++;
        S3(input);
    }
    else if (input[index] != '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        //inputRead++;
        //index++;
        //S2(input);
        Serr();
    }
}

void CommentAutomaton::S3(const std::string &input) {
    if (index >= input.size()) {
        setTokenType(TokenType::UNDEFINED);
    }
    else if (input[index] == '\n') {
        index++;
        newLines++;
        inputRead++;
        S2(input);
    }
    else if (input[index] == '#') {
        index++;
        inputRead++;
    }
    else{
        inputRead++;
        index++;
        S2(input);
    }
}