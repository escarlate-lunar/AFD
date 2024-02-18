#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "machine.h"


int main()
{   //opening archives
    std::ifstream finite_state_machine1("automata1.txt");
    std::ifstream finite_state_machine2("automata2.txt");
    std::ifstream finite_state_machine3("automata3.txt");

    //putting them on array
    std::array<std::ifstream, 3> fsm_list =
    {
        (std::move(finite_state_machine1)),
        (std::move(finite_state_machine2)),
        (std::move(finite_state_machine3))
    };

    for (auto& state_machine : fsm_list)
    {
        if (!state_machine.is_open()) //checking for fail at opening file
        {
            std::cerr << "Failed to open file" << '\n';
            continue;
        }
        
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
            case 0: //reads quantity of states
                states_quantity = std::stoi(line);
                break;
            
            case 1: //reads which states are final
                for (char state : line)
                {
                    final_states.push_back(std::stoi(&state));
                }
            
                break;
            
            case 2: //reads the alphabet characters
                alphabet = line;
                break;
            
            case 3: //reads the quantity of transitions
                transitions_quantity = std::stoi(line);
                break;
            
            default:
                if (transitions_quantity > 0) //the next lines will be read as transitions till countdown
                {
                    transitions.push_back(line);
                    transitions_quantity--;
                }

                else //gets the word at the end
                {
                    word = line;
                }

                break;
            }
        }

        machine new_machine(states_quantity, alphabet, transitions, final_states); //creates automata

        if (new_machine.check_word(word)) //checks if it is a valid word
        {
            std::cout << "Accepted word" << '\n';
        }
        else
        {
            std::cout << "Rejected word" << '\n';
        }
    }

    for (auto& fsm : fsm_list) //closes archives
    {
        fsm.close();
    }
    
    return 0;
}
