#include "state.h"

state::state(const int identifier, const bool is_final)
{
    identifier_(identifier);
    is_final_(is_final);
}

int state::get_identifier() const
{
    return identifier_;    
}

bool state::get_is_final() const
{
    return is_final_;
}