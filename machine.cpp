#include "machine.h"

#include <algorithm>
#include <utility>

machine::machine(std::list<state> states, const std::string& alphabet, const std::list<transition>& transitions):
    current_state_(NULL, NULL)
{
    alphabet_ = alphabet;
    current_state_ = states.front();
    states_ = std::move(states);
    transitions_ = (transitions);
}

bool machine::check_word(const std::string& word)
{
    for (const auto symbol : word)
    {
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
    for (auto element : transitions_)
    {
        if (element.initial_state.get_identifier() == current_state_.get_identifier() && element.symbol == symbol)
        {
            current_state_ = element.final_state;
            return true;
        }
    }

    return false;
}