#ifndef PROJECT1_RIGHTPARENAUTOMATA_H
#define PROJECT1_RIGHTPARENAUTOMATA_H

#include "Automaton.h"

class RightParenAutomata : public Automaton{
public:
    RightParenAutomata() : Automaton(TokenType::RIGHT_PAREN) {}

    void S0(const std::string& input);
};


#endif //PROJECT1_RIGHTPARENAUTOMATA_H
