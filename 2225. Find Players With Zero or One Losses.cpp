using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

//You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.
//
//Return a list answer of size 2 where:
//
//answer[0] is a list of all players that have not lost any matches.
//answer[1] is a list of all players that have lost exactly one match.
//The values in the two lists should be returned in increasing order.
//
//Note :
//
//    You should only consider the players that have played at least one match.
//    The testcases will be generated such that no two matches will have the same outcome.


//Constraints:
//
//1 <= matches.length <= 105
//matches[i].length == 2
//1 <= winneri, loseri <= 105
//winneri != loseri
//All matches[i] are unique.

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> answer{ {},{} };
        unordered_map<int, int> winnersMap;
        unordered_map<int, int> losersMap;

        for (vector<int> match: matches) {
            winnersMap[match[0]]++;
            losersMap[match[1]]++;
        }

        for (auto& winner: winnersMap) {
            if (losersMap.find(winner.first) == losersMap.end()) {
                answer[0].push_back(winner.first);
            }
        }

        for (auto& loser: losersMap) {
            if (loser.second == 1) {
                answer[1].push_back(loser.first);
            }
        }

        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());

        return answer;
    }
};