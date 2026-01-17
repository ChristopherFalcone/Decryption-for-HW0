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
    string updated_code(code);

    cout << "\n\nOLD STRING: " << code << "\n";

    // update_string_caeser(updated_code, 0, key, shifts[1]);
    // cout << "\n\nNEW STRING: " << updated_code << "\n";
    // update_string_caeser(updated_code, 1, key, shifts[2]);
    // update_string_caeser(updated_code, 2, key, shifts[5]);

    vector<char> domain_0 = {'P', 'E', 'R', 'D', 'G', 'X', 'K', 'T', 'M', 'V', 'I', 'A', 'H', 'W', 'B', 'S', 'J', 'F', 'O', 'U'};
    vector<char> range_0 = {'T', 'S', 'N', 'Y', 'O', 'A', 'U', 'E', 'R', 'H', 'I', 'P', 'M', 'L', 'G', 'W', 'C', 'D', 'B', 'K'};

    vector<char> domain_1 = {'J', 'P', 'F', 'T', 'D', 'X', 'W', 'S', 'V', 'G', 'C', 'A', 'B', 'Y', 'Q', 'E', 'N', 'R', 'Z', 'U', 'H'};
    vector<char> range_1 = {'H', 'I', 'R', 'A', 'M', 'T', 'C', 'P', 'G', 'O', 'F', 'E', 'S', 'L', 'N', 'D', 'X', 'U', 'B', 'Y', 'W'};

    vector<char> domain_2 = {'T', 'D', 'A', 'X', 'F', 'B', 'N', 'J', 'P', 'S', 'Y', 'C', 'K', 'U', 'G', 'I', 'W', 'E'};
    vector<char> range_2 = {'I', 'S', 'E', 'F', 'G', 'R', 'T', 'H', 'O', 'U', 'N', 'D', 'A', 'B', 'M', 'C', 'P', 'Y'};

    update_string_custom_vector(updated_code, 0, key, domain_0, range_0);
    update_string_custom_vector(updated_code, 1, key, domain_1, range_1);
    update_string_custom_vector(updated_code, 2, key, domain_2, range_2);

    // update_string_custom(updated_code, 0, key, 'P', 'T');
    // update_string_custom(updated_code, 1, key, 'J', 'H');
    // update_string_custom(updated_code, 2, key, 'T', 'I');
    // update_string_custom(updated_code, 0, key, 'E', 'S');
    // update_string_custom(updated_code, 1, key, 'P', 'I');
    // update_string_custom(updated_code, 2, key, 'D', 'S');
    // update_string_custom(updated_code, 2, key, 'A', 'E');
    // update_string_custom(updated_code, 2, key, 'X', 'F');
    // update_string_custom(updated_code, 1, key, 'F', 'R');
    // update_string_custom(updated_code, 1, key, 'T', 'A');
    // update_string_custom(updated_code, 2, key, 'F', 'G');

    cout << "\n\nNEW STRING: " << updated_code << "\n";

    // while (true)
    // {
    //     cout << ""
    // }

    return 0;
}