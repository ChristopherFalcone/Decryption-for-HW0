#ifndef CRYPTOHELPER_HPP
#define CRYPTOHELPER_HPP

#include <string>
#include <map>
#include <vector>

//global constants
const std::string code = "PJTE PD PJA AYKIQNTNN GC NVA XIFDP TDEPFRDARX TR GSM WBDSNGVBXSJD WPKFDT CPM XJIB KEBTBQGTQN AYAXBA ERUHPN PJA AYKIQNTNN GC NVPD TQIMUWPPPR TD XQ AHTTW TMGQF SPNV T DVGBP FAAGBP EAEWBIZTRV NVA CICXTFARX GGQPXYWVTUTXTJ WTAJAMB SEAC IQ NVA ARWBDSNIGY FADJFTOA JGH EGR IMTIUAC PJTE TDEPFRDARX NVAY FANTFGIQA IC IVTNBSN GF DGDA GXJTF KI TDEPDPTYP WKR JAWS IMTIU XJIB KEBTBQGTQN PJTE TDEPFRDARX TE EST PY GQA HGYPJ DPTBPPYB CBGD NGEKD";
const char ALPHABET[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const int index_of_e = 4;

//helper functions
void insert_into_map(std::map<std::string, std::vector<int>>&);
std::vector<int> differences_in_length(const std::map<std::string, std::vector<int>>&);
int check_for_key(const std::vector<int>&);
void fill_bins_w_frequency(std::vector<std::map<char, int>>&);
char find_largest(std::map<char, int>&);
char find_largest(std::map<char, int>&, char);
int compare_frequencies(char target);

template<typename T>
inline void print_array(T arr)
{
    for (auto itr = arr.begin(); itr != arr.end(); ++itr) 
        std::cout << *itr << " ";
}

template<typename T>
inline void print_map_to_terminal(T map)
{
    std::cout << "\nMap: \n";
    for (auto itr = map.begin(); itr != map.end(); ++itr) 
        std::cout << itr -> first << " " << itr -> second << "\n";
}

template<typename T>
void print_map_arr_to_terminal(T map)
{
    std::cout << "\nMap: \n";
    for (auto itr = map.begin(); itr != map.end(); ++itr)
    {
        std::cout << itr -> first << " ";
        auto arr = itr -> second;
        print_array(arr);
        std::cout << "\n";
    }
}

#endif