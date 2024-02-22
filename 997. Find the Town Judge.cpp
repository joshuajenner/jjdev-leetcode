// In a town, there are n people labeled from 1 to n.
// There is a rumor that one of these people is secretly the town judge.
//
// If the town judge exists, then:
//
// The town judge trusts nobody.
// Everybody(except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.
// If a trust relationship does not exist in trust array, then such a trust relationship does not exist.
//
// Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

using namespace std;
#include <vector>

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        vector<vector<int>> trustMap(n + 1, vector<int>{0, 0});

        for (vector<int> t : trust)
        {
            trustMap[t[0]][0] = 1;
            trustMap[t[1]][1] += 1;
        }

        for (int m = 1; m < trustMap.size(); m++)
        {
            if (trustMap[m][0] == 0 && trustMap[m][1] == n - 1)
            {
                return m;
            }
        }

        return -1;
    }
};