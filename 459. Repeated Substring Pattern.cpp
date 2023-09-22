#include <string>
using namespace std;

// Given a string s, check if it can be constructed by taking a substring 
// of it and appending multiple copies of the substring together.

bool repeatedSubstringPattern(string);


bool repeatedSubstringPattern(string s)
{
	int patternCompareIndex = 1;
	for (int patternLength = 1; patternLength <= (s.length() / 2); patternLength++)
	{
		string pattern1 = s.substr(0, patternLength);
		string pattern2 = s.substr(patternCompareIndex, patternLength);
		patternCompareIndex++;

		if (pattern1 == pattern2)
		{
			bool patternIsCorrect = true;
			for (int checkIndex = 0; checkIndex < s.length(); checkIndex += patternLength)
			{
				if (s.substr(checkIndex, patternLength) != pattern1) {
					patternIsCorrect = false;
					break;
				}
			}
			if (patternIsCorrect)
			{
				return true;
			}
		}

	}
	return false;
}