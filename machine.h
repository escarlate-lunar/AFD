#pragma once
#include <list>
#include <string>

#include "state.h"

struct transition
{
    int initial_state;
    char symbol;
    int final_state;
};

class machine
{
    std::string alphabet_;
    state current_state_;
    std::list<state> states_;
    std::list<transition> transitions_;

public:
    machine(std::list<state> states, const std::string& alphabet, const std::list<transition>& transitions);
    bool check_word(const std::string& word);
    bool transition_function(char symbol);
};
