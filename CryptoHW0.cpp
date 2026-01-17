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
    vector<int> shifts;

    //show all frequency info
    for (int i = 0; i < bins.size(); ++i)
    {
        char largest = find_largest(bins[i]);
        char second_largest = find_largest(bins[i], largest);
        
        int first_shift = compare_frequencies(largest);
        int second_shift = compare_frequencies(second_largest);
        shifts.push_back(first_shift);
        shifts.push_back(second_shift);

        print_map_to_terminal(bins[i]);

        cout << "Largest Char in map " << i << ": " << largest << "\n";
        cout << "Distance to shift " << i << ": " << first_shift << "\n";
        cout << "Second Largest Char in map " << i << ": " << second_largest << "\n";
        cout << "Distance to shift " << i << ": " << second_shift << "\n";
    }

    //output all possible shifts
    //update_string(shifts);

    return 0;
}