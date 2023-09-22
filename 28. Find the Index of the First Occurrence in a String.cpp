#include <string>
using namespace std;

// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack,
// or -1 if needle is not part of haystack.

int strStr(string, string);


int strStr(string haystack, string needle)
{
	// build in method
	// return haystack.find(needle);

	for (int hayIndex = 0; hayIndex < haystack.length(); hayIndex++)
	{
		bool needleFound = true;
		for (int needleIndex = 0; needleIndex < needle.length(); needleIndex++)
		{
			if (haystack[hayIndex + needleIndex] != needle[needleIndex])
			{
				needleFound = false;
				break;
			}
		}
		if (needleFound)
		{
			return hayIndex;
		}
	}

	return -1;
}