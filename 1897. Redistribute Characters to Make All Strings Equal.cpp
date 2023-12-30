#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// You are given an array of strings words (0-indexed).

// In one operation, pick two distinct indices iand j, where words[i] is a non - empty string, and move any character from words[i] to any position in words[j].

// Return true if you can make every string in words equal using any number of operations, and false otherwise.


bool makeEqual(vector<string>& words);

bool makeEqual(vector<string>& words)
{
	int wordsCount = words.size();
	unordered_map<char, int> charCounts;

	for (string word: words) 
	{
		for (char c: word) 
		{
			charCounts[c]++;
		}
	}

	for (auto count : charCounts) 
	{
		if (count.second % wordsCount != 0) 
		{
			return false;
		}
	}

	return true;
}