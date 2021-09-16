#ifndef PROJECT1_Q_MARK_H
#define PROJECT1_Q_MARK_H

#include "Automaton.h"

class Q_MARKAutomaton : public Automaton{
public:
    Q_MARKAutomaton() : Automaton(TokenType::Q_MARK) {}

    void S0(const std::string& input);
};


#endif //PROJECT1_Q_MARK_H
