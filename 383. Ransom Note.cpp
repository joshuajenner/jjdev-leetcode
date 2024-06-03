// Given two strings ransomNote and magazine, return true if ransomNote can be constructed 
// by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

#include <string>
#include <unordered_map>
#include <vector>

bool canConstruct(std::string ransomNote, std::string magazine) 
{
    std::vector<int> freq(26);

    for (char& m: magazine) 
    {
        freq[m - 'a']++;
    }

    for (char& r: ransomNote) 
    {
        freq[r - 'a']--;
        
        if (freq[r - 'a'] < 0) 
        {
            return false;
        }
    }

    return true;
}

// bool canConstruct(std::string ransomNote, std::string magazine) 
// {
//     std::unordered_map<char, int> magazineMap;

//     for (char m: magazine) 
//     {
//         magazineMap[m]++;
//     }

//     for (char r: ransomNote) 
//     {
//         magazineMap[r]--;

//         if (magazineMap[r] < 0) 
//         {
//             return false;
//         }
//     }

//     return true;
// }