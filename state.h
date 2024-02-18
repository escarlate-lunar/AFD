#pragma once

class state
{
    int identifier_;
    bool is_final_;
    
public:
    state(int identifier, bool is_final);
    int get_identifier() const;
    bool get_is_final() const;
};
