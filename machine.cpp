#include "machine.h"

#include <algorithm>
#include <utility>

machine::machine(std::list<state> states, const std::string& alphabet, const std::list<transition>& transitions):
    current_state_(NULL, NULL) //initializing variable
{
    alphabet_ = alphabet;
    current_state_ = states.front();
    states_ = std::move(states);
    transitions_ = (transitions);
}

bool machine::check_word(const std::string& word)
{
    for (char symbol : word)
    {
        if (alphabet_.find(symbol) == std::string::npos)
        {
            return false;
        }
        
        if (transition_function(symbol) == false)
        {
            return false;
        }
    }

    if (current_state_.get_is_final() == true)
    {
        return true;
    }

    return false;
}

bool machine::transition_function(const char symbol)
{
    for (transition element : transitions_)
    {
        if (element.initial_state == current_state_.get_identifier() && element.symbol == symbol)
        {
            /*
            TODO: return final state to current state
             
            auto it = std::find(states_.begin(), states_.end(), [element, this](const state s)
            {
                if (s.get_identifier() == element.final_state)
                {
                    return s;     
                }
            });

            current_state
            
            return true;
            */
        }
    }

    return false;
}