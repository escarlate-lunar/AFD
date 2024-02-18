#include "machine.h"

#include <algorithm>
#include <iostream>

machine::machine
(const int state_quantity, const std::string& alphabet, const std::list<std::string>& transitions, const std::list<int>& final_states)
{
    alphabet_ = alphabet;
    current_state_ = 1;
    state_quantity_ = state_quantity;
    final_states_ = final_states;
    transitions_ = transitions;
}

bool machine::check_word(const std::string& word)
{
    if (transitions_.empty())                                  //checks for transitions 
    {
        return false;
    }
        
    for (const char symbol : word)
    {
        if (alphabet_.find(symbol) == std::string::npos)        //checks if the letter is on the alphabet
        {
            return false;
        }
        
        if (transition_function(symbol) == false)               //checks if its possible to transition
        {
            return false;
        }
    }

    const bool is_final = find(final_states_.begin(), final_states_.end(), current_state_) != final_states_.end();
    
    if (is_final)                                                //checks for final state
    {
        return true;
    }

    return false;
}

bool machine::transition_function(const char symbol)
{
    for (const std::string& element : transitions_)
    {
        if (is_out_of_bounds(element[0]) || is_out_of_bounds(element[2]))
        {
            return false;
        }
        
        if (element[0] == current_state_ && element[1] == symbol)
        {
            current_state_ = std::stoi(element.substr(2));
            return true;
        }
    }

    return false;
}

bool machine::is_out_of_bounds(const int number) const
{
    return number < 1 || number > state_quantity_;
}
