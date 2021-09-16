#ifndef PROJECT1_LEFTPARENAUTOMATA_H
#define PROJECT1_LEFTPARENAUTOMATA_H

#include "Automaton.h"

class LeftParenAutomata : public Automaton{
public:
    LeftParenAutomata() : Automaton(TokenType::LEFT_PAREN){}

    void S0(const std::string& input);
};


#endif //PROJECT1_LEFTPARENAUTOMATA_H
