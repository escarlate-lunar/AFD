#include <algorithm>
#include <array>
#include <iostream>
#include <fstream>
#include <list>
#include <string>

#include "machine.h"

int main()
{
    std::ifstream finite_state_machine1("");
    std::ifstream finite_state_machine2("");
    std::ifstream finite_state_machine3("");

    std::array<std::ifstream, 3> fsm_list =
    {
        (std::move(finite_state_machine1)),
        (std::move(finite_state_machine2)),
        (std::move(finite_state_machine3))
    };

    for (auto& state_machine : fsm_list)
    {
        int states_quantity = 0;
        int transitions_quantity = 0;
        std::list<int> final_states;
        std::list<std::string> transitions;
        std::string alphabet, word;
        std::string line;
        
        for (int i = 0; std::getline(state_machine, line); ++i)
        {
            switch (i)
            {
            case 0:
                states_quantity = std::stoi(line);
                continue;
            
            case 1:
                std::string final_states_list;

                for (char state : final_states_list)
                {
                    final_states.push_back(std::stoi(&state));
                }
            
                continue;
            
            case 2:
                alphabet = line;
                continue;
            
            case 3:
                transitions_quantity = std::stoi(line);
                continue;
            
            default: break;
            }

            if (transitions_quantity != 0)
            {
                transitions.push_back(line);
                transitions_quantity--;

                continue;
            }

            word = line;
        }

        std::list<state> states;

        for (int j = 0; j < states_quantity; ++j)
        {
            auto is_final = std::find(final_states.begin(), final_states.end(), j+1);
            state new_state(j+1, is_final != final_states.end());
            states.push_back(new_state);
        }

        machine new_machine(states, alphabet,);
    }


    std::for_each(fsm_list.begin(), fsm_list.end(), [](std::ifstream fsm)
    {
        fsm.close();
    });
    
    return 0;
}
