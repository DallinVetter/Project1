#include "Q_MARK.h"

void Q_MARKAutomaton::S0(const std::string &input) {
    if (input[index] == '?') {
        inputRead = 1;
    }
    else{
        Serr();
    }
}