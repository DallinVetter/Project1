#ifndef PROJECT1_ADDAUTOMATON_H
#define PROJECT1_ADDAUTOMATON_H

#include "Automaton.h"

class AddAutomaton : public Automaton{
public:
    AddAutomaton():Automaton(TokenType::ADD) {}

    void S0(const std::string& input);

};


#endif //PROJECT1_ADDAUTOMATON_H
