using namespace std;

// You are given an integer n, the number of teams in a tournament that has strange rules:

// If the current number of teams is even, each team gets paired with another team.
// A total of n / 2 matches are played, and n / 2 teams advance to the next round.

// If the current number of teams is odd, one team randomly advances in the tournament, and the rest gets paired.
// A total of(n - 1) / 2 matches are played, and (n - 1) / 2 + 1 teams advance to the next round.


// Return the number of matches played in the tournament until a winner is decided.

int numberOfMatches(int n);

int numberOfMatches(int n)
{
	int teamsLeft = n;
	int matchesPlayed = 0;

	while (teamsLeft > 1) 
	{
		if (teamsLeft % 2 == 0) 
		{
			matchesPlayed += teamsLeft / 2;
			teamsLeft = teamsLeft / 2;
		}
		else 
		{
			matchesPlayed += (teamsLeft - 1) / 2;
			teamsLeft = ((teamsLeft - 1) / 2) + 1;
		}
	}

	return matchesPlayed;
}