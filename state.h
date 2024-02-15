#pragma once

class state
{
    int identifier_;
    bool is_final_;
    
public:
    state(const int identifier, const bool is_final);
    int get_identifier() const;
    bool get_is_final() const;
};
