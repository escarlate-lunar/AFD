#pragma once
#include <list>
#include <string>

class machine
{
    std::string alphabet_;
    int current_state_;
    int state_quantity_;
    std::list<int> final_states_;
    std::list<std::string> transitions_;

public:
    machine(int state_quantity, const std::string& alphabet, const std::list<std::string>& transitions, const std::list<int>& final_states);
    bool check_word(const std::string& word);
    bool transition_function(char symbol);
    bool is_out_of_bounds(int number) const;
};
