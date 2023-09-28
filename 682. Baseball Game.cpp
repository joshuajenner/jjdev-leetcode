#include <string>
#include <vector>
using namespace std;

// You are keeping the scores for a baseball game with strange rules. 
// At the beginning of the game, you start with an empty record.

// You are given a list of strings operations, where operations[i] is the ith operation 
// you must apply to the record and is one of the following:

// An integer x.
// Record a new score of x.
// '+'.
// Record a new score that is the sum of the previous two scores.
// 'D'.
// Record a new score that is the double of the previous score.
// 'C'.
// Invalidate the previous score, removing it from the record.
// Return the sum of all the scores on the record after applying all the operations.
//
// The test cases are generated such that the answer and 
// all intermediate calculations fit in a 32 - bit integer and that all operations are valid.


int calPoints(vector<string>& operations);

int calPoints(vector<string>& operations)
{
	int totalScore = 0;
	vector<int> previousScores = {};
	for (string instruction : operations)
	{
		if (instruction == "+")
		{
			previousScores.push_back(previousScores.back()  + previousScores.at(previousScores.size() - 2));
			totalScore += previousScores.back();

		}
		else if (instruction == "D")
		{	
			previousScores.push_back(previousScores.back() * 2);
			totalScore += previousScores.back();
		}
		else if (instruction == "C")
		{
			totalScore -= previousScores.back();
			previousScores.pop_back();
		}
		else
		{
			int newScore = stoi(instruction);
			totalScore += newScore;
			previousScores.push_back(newScore);
		}	
	}
	return totalScore;
}