#include <sstream>
#include "Cryptohelper.hpp"

using namespace std;

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
    return 1;
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

int compare_frequencies(char target)
{
    int position = 0;
    for (position; position < 26; ++position)
    {
        if (ALPHABET[position] == target) break;
    }
    return index_of_e - position;
}

void update_string_caeser(string& target, int index, int key, int shift)
{   
    int count = 0;
    for (auto itr = target.begin(); itr != target.end(); ++itr)
    {
        char letter = *itr;
        if (letter == ' ')
        {
            continue;
        }
        if (count == key)
        {
            count = 0;
        }

        if (count == index)
        {
            ++count;
        }
        else
        {
            ++count;
            continue;
        }

        for (int i = 0; i < 26; ++i)
        {
            if (ALPHABET[i] == letter)
            {
                int new_position = i + shift;
                if (new_position > 25)
                {
                    new_position -= 26;
                }
                else if (new_position < 0)
                {
                    new_position += 26;
                }
                *itr = ALPHABET[new_position];
                break;
            }
        }
    }
}

void update_string_custom(string& target, int index, int key, char chosen, char new_chosen)
{   
    int count = 0;
    for (auto itr = target.begin(); itr != target.end(); ++itr)
    {
        char letter = *itr;
        if (letter == ' ')
        {
            continue;
        }
        if (count == key)
        {
            count = 0;
        }

        if (count == index)
        {
            ++count;
        }
        else
        {
            ++count;
            continue;
        }

        if (letter == chosen)
        {
            *itr = new_chosen;
        }
    }
}

void update_string_custom_vector(string& target, int index, int key, vector<char> chosen, vector<char> new_chosen)
{   
    int count = 0;
    for (auto itr = target.begin(); itr != target.end(); ++itr)
    {
        char letter = *itr;
        if (letter == ' ')
        {
            continue;
        }
        if (count == key)
        {
            count = 0;
        }

        if (count == index)
        {
            ++count;
        }
        else
        {
            ++count;
            continue;
        }

        for (int i = 0; i < chosen.size(); ++i)
        {
            if (letter == chosen[i])
            {
                *itr = new_chosen[i];
            }
        }
    }
}