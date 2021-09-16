//
// Created by Dallin Vetter on 9/13/21.
//

#ifndef PROJECT1_RULESAUTOMATON_H
#define PROJECT1_RULESAUTOMATON_H

#include "Automaton.h"

class RulesAutomaton : public Automaton {
public:
    RulesAutomaton() : Automaton(TokenType::RULES) {}
    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
};


#endif //PROJECT1_RULESAUTOMATON_H
