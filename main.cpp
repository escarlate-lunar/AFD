#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "machine.h"


int main()
{
    //getting file name;
    std::string filename;
    std::cout << "Enter file name: ";
    std::cin >> filename;
    
    //opening archive
    std::ifstream finite_state_machine1(filename);
    
    if (!finite_state_machine1.is_open()) //checking for fail at opening file
    {
        std::cerr << "Failed to open file" << '\n';
        return 0;
    }
        
    int states_quantity = 0;
    int transitions_quantity = 0;
    std::list<int> final_states;
    std::list<std::string> transitions;
    std::string alphabet, word;
    std::string line;
        
    for (int i = 0; std::getline(finite_state_machine1, line); ++i)
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
    
    finite_state_machine1.close();
    
    return 0;
}
