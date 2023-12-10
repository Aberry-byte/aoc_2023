#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::ifstream;
using std::string;
using std::vector;
using std::stoi;
using std::endl;


int main(int argc, char** argv)
{
    string line;
    int sum = 0;
    ifstream input("test_file.txt");
    if (input.is_open())
    {
        while(getline(input, line))
        {
            string number_in_line = "";
            for (char c : line)
            {
                if (isdigit(c))
                {
                    number_in_line += c;
                }
                
            }
            char front = number_in_line.front();
            char end = number_in_line.back();
            string full_number = string(1, front) + end;
            sum += stoi(full_number);
        }
    }
    cout << sum << endl;
}