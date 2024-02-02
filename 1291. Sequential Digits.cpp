//An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
//
//Return a sorted list of all the integers in the range[low, high] inclusive that have sequential digits.


#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high)
    {
        int minLength = to_string(low).length();
        int maxLength = to_string(high).length();
        vector<int> validSequences;

        for (int length = minLength; length <= maxLength; length++) 
        {
            for (int startNum = 1; startNum <= 10 - length; startNum++)
            {
                string newSeq = "";
                for (int increment = 0; increment < length; increment++) {
                    newSeq += char(startNum + increment);
                }
                int numSeq = stoi(newSeq);
                if (numSeq > low && numSeq < high) {
                    validSequences.push_back(numSeq);
                } 
            }
        }

        return validSequences;
    }
};