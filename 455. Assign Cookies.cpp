#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with;
// and each cookie j has a size s[j].If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content.

// Your goal is to maximize the number of your content children and output the maximum number.

int findContentChildren(vector<int>& g, vector<int>& s);

int findContentChildren(vector<int>& g, vector<int>& s)
{
	int childrenSatisfied = 0;
	sort(g.begin(), g.end(), greater<int>());
	sort(s.begin(), s.end(), greater<int>());

	int cookieIndex = 0;
	int childIndex = 0;

	while (cookieIndex < s.size() && childIndex < g.size()) 
	{
		if (s[cookieIndex] >= g[childIndex]) 
		{
			childrenSatisfied++;
			cookieIndex++;
			childIndex++;
		}
		else
		{
			childIndex++;
		}
	}

	return childrenSatisfied;
}