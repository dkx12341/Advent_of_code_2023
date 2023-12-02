// AOC_day_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<fstream>
#include <iostream>
#include <string>
#include<map>

using namespace std;

int extract_integers(string input)
{
    string integers;
    integers.erase();


    int pos = -1;

    for (auto i : input)
    {
        pos++;

        int j = input.find("three", pos);
        
        if (isdigit(i))
        {
            integers += i;
        }
        else
        {
            if (input.find("one", pos)!=-1)
            {
                if (input.find("one", pos) == pos)
                {
                    integers += '1';
                }
            }
            
            if (input.find("two", pos) != -1)
            {
                if (input.find("two", pos) == pos)
                {
                    integers += '2';
                }
            }

            if (input.find("three", pos) != -1)
            {
                if (input.find("three", pos) == pos)
                {
                    integers += '3';
                }
            }

            if (input.find("four", pos) != -1)
            {
                if (input.find("four", pos) == pos)
                {
                    integers += '4';
                }
            }

            if (input.find("five", pos) != -1)
            {
                if (input.find("five", pos) == pos)
                {
                    integers += '5';
                }
            }

            if (input.find("six", pos) != -1)
            {
                if (input.find("six", pos) == pos)
                {
                    integers += '6';
                }
            }

            if (input.find("seven", pos) != -1)
            {
                if (input.find("seven", pos) == pos)
                {
                    integers += '7';
                }
            }

            if (input.find("eight", pos) != -1)
            {
                if (input.find("eight", pos) == pos)
                {
                    integers += '8';
                }
            }

            if (input.find("nine", pos) != -1)
            {
                if (input.find("nine", pos) == pos)
                {
                    integers += '9';
                }
            }

        }

    }
    string end_value_string;
    end_value_string.erase();
    end_value_string += integers[0];
    end_value_string+=integers.back();
    int end_value = stoi(end_value_string);
    return end_value;
}

int process_value(string file_name)
{
    ifstream input_data;
    input_data.open(file_name);
    int value = 0;
    while (!input_data.eof())
    {
        string current_word;
        getline(input_data, current_word);
        value += extract_integers(current_word);
    }

    return value;
}

int main()
{
    int answer = process_value("input.txt");
   
    cout << answer;

    





   
}

