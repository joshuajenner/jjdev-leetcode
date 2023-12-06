using namespace std;

// Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.

// He starts by putting in $1 on Monday, the first day.
// Every day from Tuesday to Sunday, he will put in $1 more than the day before.
// On every subsequent Monday, he will put in $1 more than the previous Monday.

// Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.

int totalMoney(int n);

int totalMoney(int n)
{
	int dayOfWeek = 0;
	int moneySaved = 0;
	int mondayAmount = 0;
	int dailyAmount = 0;

	for (int i = 0; i < n; i++) 
	{
		if (dayOfWeek == 0)
		{
			mondayAmount += 1;
			moneySaved += mondayAmount;
		}
		else if (dayOfWeek == 1)
		{
			dailyAmount = mondayAmount + 1;
			moneySaved += dailyAmount;
		}
		else
		{
			dailyAmount += 1;
			moneySaved += dailyAmount;
		}

		dayOfWeek++;

		if (dayOfWeek >= 7)
		{
			dayOfWeek = 0;
		}
	}

	return moneySaved;
}