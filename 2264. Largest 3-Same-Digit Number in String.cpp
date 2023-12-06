using namespace std;

// You are given a string num representing a large integer. 
// An integer is good if it meets the following conditions:

// It is a substring of num with length 3.
// It consists of only one unique digit.
// Return the maximum good integer as a string or an empty string "" if no such integer exists.

// Note:
// A substring is a contiguous sequence of characters within a string.
// There may be leading zeroes in num or a good integer.

string largestGoodInteger(string num);

string largestGoodInteger(string num)
{
    string bestInteger = "";

    for (int index = 0; index < num.length() - 2; index++)
    {
        if (num[index] == num[index + 1] && num[index + 1] == num[index + 2])
        {
            string newGoodString = num.substr(index, 3);
            int newGoodInteger = stoi(newGoodString);

            if (bestInteger == "")
            {
                bestInteger = newGoodString;
            }
            else if (newGoodInteger > stoi(bestInteger))
            {
                bestInteger = newGoodString;
            }
        }
    }

    return bestInteger;
}