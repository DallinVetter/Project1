#ifndef PROJECT1_IDAUTOMATON_H
#define PROJECT1_IDAUTOMATON_H

#include "Automaton.h"

class IDAutomaton : public Automaton{
public:
    IDAutomaton() : Automaton(TokenType::ID){};

    void S0(const std::string& input);
    void S1(const std::string& input);

};


#endif //PROJECT1_IDAUTOMATON_H
