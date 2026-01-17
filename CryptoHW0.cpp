#include <iostream>
#include <sstream>
#include "Cryptohelper.hpp"

using namespace std;

/*
Main program that runs the decryption.
*/

int main()
{
    //Stuff for finding the Polyalphabetic Key.
    map<string, vector<int>> space_difference;
    insert_into_map(space_difference);
    print_map_arr_to_terminal(space_difference);

    vector<int> differences = differences_in_length(space_difference);
    print_array(differences);

    int key = check_for_key(differences);
    cout << "\n\nPolyalphabetic Key: " << key << "\n\n";

    //Stuff for sorting data into seperate bins.
    //This initializes a vector called bins, and puts an empty map in each element up to size: key.
    vector<map<char, int>> bins(key, map<char, int>());

    fill_bins_w_frequency(bins);

    for (int i = 0; i < bins.size(); ++i)
    {
        char largest = find_largest(bins[i]);
        char second_largest = find_largest(bins[i], largest);
        print_map_to_terminal(bins[i]);
        cout << "Largest Char in map " << i << ": " << largest << "\n";
        cout << "Second Largest Char in map " << i << ": " << second_largest << "\n";
    }

    return 0;
}

/*
Helper functions declared in Cryptohelper.hpp are defined here.
*/

void insert_into_map(map<string, vector<int>>& map)
{
    istringstream ss_in(code);
    
    string word;
    int position = 0;
    while(ss_in >> word)
    {
        if(map.contains(word))
        {
            map[word].push_back(position);
        }
        else
        {
            vector<int> v = {position};
            map.insert({word, v});
        }
        position += word.size();
    }
}

vector<int> differences_in_length(const map<string, vector<int>>& map)
{
    vector<int> differences;
    for (auto itr = map.begin(); itr != map.end(); ++itr)
    {
        vector<int> arr = itr -> second;
        int size = arr.size();
        if (size > 1)
        {
            int last = arr[size - 1];
            for (int i = size - 2; i >= 0; --i)
            {
                differences.push_back(last - arr[i]);
                last = arr[i];
            }
        }
    }
    return differences;
}

int check_for_key(const vector<int>& arr)
{
    for (int i = 2; i <= 39; ++i)
    {
        bool is_divisor = true;
        for (int num : arr)
        {
            if (num % i != 0)
            {
                is_divisor = false;
            }
        }
        if (is_divisor)
        {
            return i;
        }
    }
    return -1;
}

void fill_bins_w_frequency(vector<map<char, int>>& bins)
{
    auto itr = code.begin();
    for (int i = 0; itr != code.end(); ++i)
    {
        if (i == bins.size()) 
        {
            i = 0;
        }
        if (*itr == ' ')
        {
            ++itr;
            continue;
        }

        if (bins[i].contains(*itr))
        {
            bins[i][*itr]++;
        }
        else
        {
            bins[i].insert({*itr, 1});
        }
        ++itr;
    }
}

char find_largest(map<char, int>& m)
{
    int largest_int = 0;
    char largest_char = '\0';
    for (auto itr = m.begin(); itr != m.end(); ++itr)
    {
        char ch_value = itr -> first;
        int int_value = itr -> second;

        if (int_value > largest_int)
        {
            largest_int = int_value;
            largest_char = ch_value;
        }
    }
    return largest_char;
}

char find_largest(map<char, int>& m, char previous)
{
    int largest_int = 0;
    char largest_char = '\0';
    for (auto itr = m.begin(); itr != m.end(); ++itr)
    {
        char ch_value = itr -> first;
        int int_value = itr -> second;

        if (ch_value == previous)
        {
            continue;
        }

        if (int_value > largest_int)
        {
            largest_int = int_value;
            largest_char = ch_value;
        }
    }
    return largest_char;
}