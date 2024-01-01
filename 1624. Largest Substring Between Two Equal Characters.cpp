#include <string>
#include <unordered_map>
using namespace std;

// Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. 
// If there is no such substring return -1.

// A substring is a contiguous sequence of characters within a string.

int maxLengthBetweenEqualCharacters(string s);

int maxLengthBetweenEqualCharacters(string s)
{
	int subStringLength = -1;
	unordered_map<char, int> charIndexes;

	for (int index = 0; index < s.length(); index++) 
	{
		char checkChar = s[index];

		if (charIndexes.find(checkChar) == charIndexes.end())
		{
			charIndexes[checkChar] = index;
		}
		else
		{
			subStringLength = max(subStringLength, (index - charIndexes[checkChar] - 1));
		}
	}

	return subStringLength;
}