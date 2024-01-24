// You are given an array of strings arr. 
// A string s is formed by the concatenation of a subsequence of arr that has unique characters.

// Return the maximum possible length of s.

// A subsequence is an array that can be derived from another array by deleting some or no elements 
// without changing the order of the remaining elements.


// Constraints:

// 1 <= arr.length <= 16
// 1 <= arr[i].length <= 26
// arr[i] contains only lowercase English letters.


using namespace std;
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    // Struct to store word information - length and mask
    struct WordInfo {
        int length; // Length of the word
        int mask;   // Mask representing unique characters in the word
    };

    vector<WordInfo> wordContainer; // Container to hold unique words and their masks

    // Recursive function to find the maximum length of unique characters given a mask
    int findUniqueLength(int mask, int i) {
        if (i >= wordContainer.size())
            return 0;

        int include = 0;
        // Check if the current word can be included based on the mask condition
        if (mask == 0 || (wordContainer[i].mask | mask) == (wordContainer[i].mask + mask))
            include = wordContainer[i].length + findUniqueLength(wordContainer[i].mask | mask, i + 1);

        int exclude = findUniqueLength(mask, i + 1);
        return max(include, exclude); // Return the maximum length (either including or excluding the word)
    }

    // Function to find the maximum length of unique characters in the given array of strings
    int maxLength(vector<string>& arr) {
        sort(arr.begin(), arr.end(), greater<string>());

        // Process each word in the input array
        for (const auto& str : arr) {
            int mask = 0; // Mask representing unique characters in the current word
            bool hasDuplicates = false; // Flag to check if the word has duplicate characters
            vector<int> charCount(26, 0); // Count of each character in the word

            // Process each character in the word
            for (char ch : str) {
                int idx = ch - 'a'; // Calculate the index for the character (0 to 25 for 'a' to 'z')
                charCount[idx]++; // Increment the character count
                if (charCount[idx] > 1) {
                    hasDuplicates = true; // If count > 1, it means the character is duplicated
                    break;
                }
                int x = (1 << idx); // Calculate the mask for the character
                mask |= x; // Update the word mask with the new character's mask
            }

            // If the word has duplicate characters, skip it
            if (hasDuplicates)
                continue;

            // Add the word to the container with its length and mask
            wordContainer.push_back({ static_cast<int>(str.size()), mask });
        }

        // Start the recursive function with initial mask 0 and word index 0
        return findUniqueLength(0, 0);
    }
};