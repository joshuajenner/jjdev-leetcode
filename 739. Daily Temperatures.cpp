//Given an array of integers temperatures represents the daily temperatures, return an array answer such that 
//answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
//If there is no future day for which this is possible, keep answer[i] == 0 instead.

//Constraints:
//
//1 <= temperatures.length <= 105
//30 <= temperatures[i] <= 100

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> daysToWait(temperatures.size());
        int lastSeenIndex[101] = {};

        for (int index = temperatures.size() - 1; index >= 0; index--)
        {
            cout << "Index: " << index << " > ";

            lastSeenIndex[temperatures[index]] = index;

            bool isSeen = false;
            int closestIndex = temperatures.size();

            for (int checkTemp = temperatures[index]; checkTemp < 100; checkTemp++) 
            {
                if (lastSeenIndex[checkTemp] != 0 && lastSeenIndex[checkTemp] < closestIndex)
                {
                    closestIndex = lastSeenIndex[checkTemp];
                    isSeen = true;
                    cout << "Seen: " << closestIndex;
                }
            }

            if (isSeen) {
                daysToWait[index] = closestIndex - index;
            }
            else {
                daysToWait[index] = 0;
            }

            cout << endl;
        }


        cout << endl;
        for (int p = 0; p < 101; p++) {
            if (lastSeenIndex[p] != 0) {
                cout << "Found " << p << " at " << lastSeenIndex[p] << endl;
            }
        }

        
        return daysToWait;
    }
};




/*vector<int> daysToWait;

for (int check = 0; check < temperatures.size(); check++)
{
    int waitTime = 0;
    for (int temp = 0; temp < temperatures.size(); temp++)
    {
        if (temperatures[temp] > temperatures[check]) {
            waitTime = temp - check;
            break;
        }
    }
    daysToWait.push_back(waitTime);
}

return daysToWait;*/