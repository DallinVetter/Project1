#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "Q_MARK.h"
#include "LeftParenAutomata.h"
#include "RightParenAutomata.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"
#include "IDAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"
#include <iostream>




Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new Q_MARKAutomaton);
    automata.push_back(new LeftParenAutomata);
    automata.push_back(new RightParenAutomata);
    automata.push_back(new MultiplyAutomaton);
    automata.push_back(new AddAutomaton);
    automata.push_back(new SchemesAutomaton);
    automata.push_back(new FactsAutomaton);
    automata.push_back(new RulesAutomaton);
    automata.push_back(new QueriesAutomaton);
    automata.push_back(new IDAutomaton);
    automata.push_back(new StringAutomaton);
    automata.push_back(new CommentAutomaton);



    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    /*
    set lineNumber to 1
    // While there are more characters to tokenize
    loop while input.size() > 0 {
        set maxRead to 0
        set maxAutomaton to the first automaton in automata

        // TODO: you need to handle whitespace inbetween tokens

        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        foreach automaton in automata {
            inputRead = automaton.Start(input)
            if (inputRead > maxRead) {
                set maxRead to inputRead
                set maxAutomaton to automaton
            }
        }
        // Here is the "Max" part of the algorithm
        if maxRead > 0 {
            set newToken to maxAutomaton.CreateToken(...)
                increment lineNumber by maxAutomaton.NewLinesRead()
                add newToken to collection of all tokens
        }
        // No automaton accepted input
        // Create single character undefined token
        else {
            set maxRead to 1
                set newToken to a  new undefined Token
                (with first character of input)
                add newToken to collection of all tokens
        }
        // Update `input` by removing characters read to create Token
        remove maxRead characters from input
    }
    add end of file token to all tokens
    */
    int lineNumber = 1;
    while (input.size() > 0) {
        int maxRead = 0;
        Automaton* maxAutomaton = automata.at(0);

        while(isspace(input.at(0))) {
            if (input.at(0) == '\n') {
                ++lineNumber;
                (input.erase(0, 1));
            }
            else {
                (input.erase(0, 1));
            }
        }

        for (Automaton* currAutomaton : automata) {
            int inputRead = currAutomaton->Start(input);
            if (inputRead > maxRead){
                maxRead = inputRead;
                maxAutomaton = currAutomaton;
            }
        }

        if (maxRead > 0) {
            std::string description = input.substr(0, maxAutomaton->GetInputRead());
            Token* newToken = maxAutomaton->CreateToken(description, lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }

        else if(input[0] != '\n'){
            maxRead = 1;
            std::string description = input.substr(0, 1);
            Token* newToken = new Token(TokenType::UNDEFINED, description, lineNumber);
            //lineNumber += maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }

        input.erase(0, maxRead);

        if (input[0] == '\n') {
            lineNumber++;
            input.erase(0,1);
        }
    }
    lineNumber++;
    Token* newToken = new Token(TokenType::ENDOFFILE, "", lineNumber);
    tokens.push_back(newToken);

    for (unsigned int tokensIterator = 0; tokensIterator < tokens.size(); ++tokensIterator) {
        std::cout << tokens.at(tokensIterator)->toString() << std::endl;
    }
    std::cout << "Total Tokens = " << std::to_string(tokens.size());
    //TODO: ADD EOF token
}
