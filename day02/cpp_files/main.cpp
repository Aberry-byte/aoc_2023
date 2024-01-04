#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "bag.hpp"

using namespace std;

void update_last_seen_num(char c, int* int_address);


int main(int argc, char** argv)
{
    // Load configuration
    Bag elf_bag = Bag(12, 13, 14);

    // read file
    ifstream input("../test_file.txt");
    if (input.is_open())
    {
        string line;
        int valid_game_number_sum = 0;
        while (getline(input, line))
        {
            int* last_num_seen = new int;
            int game_number;
            char last_char_seen;
            int picked_red, picked_green, picked_blue = 0;
            for (char c : line)
            {
                if (c == ':')
                {
                    // character before is Game number
                    game_number = *last_num_seen;
                }
                if (c == ',')
                {
                    // reached end of statement
                    if (last_char_seen == 'd')
                    {
                        // red number
                        picked_red = *last_num_seen;
                    }
                    else if (last_char_seen == 'n')
                    {
                        // green number
                        picked_green = *last_num_seen;
                    }
                    else if (last_char_seen == 'e')
                    {
                        // blue number
                        picked_blue = *last_num_seen;
                    }
                    else
                    {
                        cout << "Last char seen was " << last_char_seen << "shit broke\n";
                        exit(1);
                    }
                }
                if (c == ';')
                {
                    // reached end of statement
                    if (last_char_seen == 'd')
                    {
                        // red number
                        picked_red = *last_num_seen;
                    }
                    else if (last_char_seen == 'n')
                    {
                        // green number
                        picked_green = *last_num_seen;
                    }
                    else if (last_char_seen == 'e')
                    {
                        // blue number
                        picked_blue = *last_num_seen;
                    }
                    else
                    {
                        cout << "Last char seen was " << last_char_seen << "shit broke\n";
                        exit(1);
                    }
                    cout << "READ ;\n";
                    cout << picked_red << " " << picked_green << " " << picked_blue << endl;
                    if (elf_bag.valid_pull(picked_red, picked_green, picked_blue))
                    {
                        cout << "ADDED " << game_number << endl;
                        valid_game_number_sum += game_number;
                    }
                    picked_red = picked_green = picked_blue = 0;
                }
                // update before next loop
                last_char_seen = c;
                update_last_seen_num(c, last_num_seen);
            }
            
        }
        cout << valid_game_number_sum << endl;
    }
}

void update_last_seen_num(char c, int* int_address)
{
    if (isdigit(c))
    {
        *int_address = stoi(string(1, c));
    }
}