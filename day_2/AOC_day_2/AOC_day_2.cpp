// AOC_day_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

struct Game
{
    int id=0;
    int max_green_cubes=0;
    int max_blue_cubes=0;
    int max_red_cubes=0;
    bool possible=true;
};

const int green_cubes_in_game = 13;
const int blue_cubes_in_game = 14;
const int red_cubes_in_game = 12;

Game read_game_data(string input)
{
    Game current_game;
    string temp_word;
    string temp_value;
    int temp_pos = 0;
    temp_pos = input.find(':');
    temp_word = input.substr(input.find("Game") + 5, temp_pos - input.find(' ')-1);
    current_game.id = stoi(temp_word);

    for(int i = input.find(':'); i<input.length() - 1;)
    {
        i = input.find(' ', i);
        temp_pos = input.find(' ', i+1)-1;
        temp_value = input.substr(i + 1, temp_pos - i);

        vector<int> tab;
        tab.push_back(input.find(',', i)-1);
        tab.push_back(input.find(';', i)-1);
        tab.push_back(input.length()-1);
        int min=tab[2];
        for (auto j : tab)
        {
            if (j < min&& j!= -2)
            {
                min = j;
            }
        }
        i = min;

        temp_word = input.substr(temp_pos + 2, i - temp_pos-1);

        if (temp_word == "red")
        {
            if (current_game.max_red_cubes < stoi(temp_value))
            {
                current_game.max_red_cubes = stoi(temp_value);
            }
        }

        if (temp_word == "blue")
        {
            if (current_game.max_blue_cubes < stoi(temp_value))
            {
                current_game.max_blue_cubes = stoi(temp_value);
            }
        }

        if (temp_word == "green")
        {
            if (current_game.max_green_cubes < stoi(temp_value))
            {
                current_game.max_green_cubes = stoi(temp_value);
            }
        }
    }

    if (current_game.max_blue_cubes > blue_cubes_in_game)
    {
        current_game.possible = false;
    }

    if (current_game.max_green_cubes > green_cubes_in_game)
    {
        current_game.possible = false;
    }

    if (current_game.max_red_cubes > red_cubes_in_game)
    {
        current_game.possible = false;
    }

    return current_game;
}

void process_value(string file_name)
{
    ifstream input_data;
    input_data.open(file_name);
    int value = 0;
    int value_2 = 0;
    while (!input_data.eof())
    {
        string current_game_data;
        getline(input_data, current_game_data);
        Game current_game = read_game_data(current_game_data);
        if (current_game.possible == true)
        {
            value += current_game.id;
        }
        int game_pow = current_game.max_blue_cubes * current_game.max_green_cubes * current_game.max_red_cubes;
        value_2 += game_pow;
    }

    cout << value << "\n"<<value_2;

    
}


int main()
{
    process_value("data.txt");
}

