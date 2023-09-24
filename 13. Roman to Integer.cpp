#include <string>
using namespace std;

// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.

int romanToInt(string s);

int romanToInt(string s)
{
    int sum = 0;
    for (int charIndex = 0; charIndex < s.length(); charIndex++)
    {
        switch (s[charIndex])
        {
        case 'I':
            if (s[charIndex + 1] == 'V')
            {
                sum += 4;
                charIndex++;
            }
            else if (s[charIndex + 1] == 'X')
            {
                sum += 9;
                charIndex++;
            }
            else
            {
                sum += 1;
            }
            break;
        case 'V':
            sum += 5;
            break;
        case 'X':
            if (s[charIndex + 1] == 'L')
            {
                sum += 40;
                charIndex++;
            }
            else if (s[charIndex + 1] == 'C')
            {
                sum += 90;
                charIndex++;
            }
            else
            {
                sum += 10;
            }
            break;
        case 'L':
            sum += 50;
            break;
        case 'C':
            if (s[charIndex + 1] == 'D')
            {
                sum += 400;
                charIndex++;
            }
            else if (s[charIndex + 1] == 'M')
            {
                sum += 900;
                charIndex++;
            }
            else
            {
                sum += 100;
            }
            break;
        case 'D':
            sum += 500;
            break;
        case 'M':
            sum += 1000;
            break;
        }
    }
    return sum;
}