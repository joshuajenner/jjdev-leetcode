#include <vector>
#include <algorithm>
using namespace std;

// We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

// You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

// If you choose a job that ends at time X you will be able to start another job that starts at time X.

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit);

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
{
    int numJobs = profit.size(); // Number of jobs
    vector<tuple<int, int, int>> jobs(numJobs);

    for (int i = 0; i < numJobs; ++i) {
        jobs[i] = { endTime[i], startTime[i], profit[i] };
    }

    sort(jobs.begin(), jobs.end());
    vector<int> dp(numJobs + 1);

    for (int i = 0; i < numJobs; ++i) {
        auto [endTime, startTime, profit] = jobs[i];

        int latestNonConflictJobIndex = upper_bound(jobs.begin(), jobs.begin() + i, startTime, [&](int time, const auto& job) -> bool {
            return time < get<0>(job);
            }) - jobs.begin();

            dp[i + 1] = max(dp[i], dp[latestNonConflictJobIndex] + profit);
    }

    return dp[numJobs];
}