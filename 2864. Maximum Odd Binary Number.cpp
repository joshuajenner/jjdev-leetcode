//You are given a binary string s that contains at least one '1'.
//
//You have to rearrange the bits in such a way that the resulting binary number is 
//the maximum odd binary number that can be created from this combination.
//
//Return a string representing the maximum odd binary number that can be created from the given combination.
//
//Note that the resulting string can have leading zeros.

using namespace std;
#include <string>

class Solution {
public:
    string maximumOddBinaryNumber(string s) 
    {
        int oneCount = 0;
        int zeroCount = 0;
        
        for (char c: s) {
            if (c == '1') {
                oneCount++;
            }
        }
        zeroCount = s.length() - oneCount;

        return string(--oneCount, '1') + string(zeroCount, '0') + '1';
    }
};