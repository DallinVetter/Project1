#ifndef PROJECT1_MULTIPLYAUTOMATON_H
#define PROJECT1_MULTIPLYAUTOMATON_H
\
#include "Automaton.h"

class MultiplyAutomaton : public Automaton{
public:
    MultiplyAutomaton() : Automaton(TokenType::MULTIPLY){}

    void S0(const std::string& input);
};


#endif //PROJECT1_MULTIPLYAUTOMATON_H
