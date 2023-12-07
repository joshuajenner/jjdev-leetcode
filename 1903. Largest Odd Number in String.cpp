using namespace std;

// You are given a string num, representing a large integer. 
// Return the largest-valued odd integer (as a string) that is 
// a non-empty substring of num, or an empty string "" if no odd integer exists.

// A substring is a contiguous sequence of characters within a string.

string largestOddNumber(string num);

string largestOddNumber(string num)
{
	for (int index = num.length() - 1; index >= 0; index--)
	{
		if (int(num[index]) % 2 != 0)
		{
			return num.substr(0, index + 1);
		}
	}
	return "";
}