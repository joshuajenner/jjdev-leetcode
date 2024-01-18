#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> totalOccurs;
        unordered_set<int> uniqueOccurs;

        for (int num: arr) {
            totalOccurs[num]++;
        }

        for (auto occur : totalOccurs) {
            uniqueOccurs.insert(occur.second);
        }

        return totalOccurs.size() == uniqueOccurs.size();
    }
};