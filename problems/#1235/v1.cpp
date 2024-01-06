class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int curr, n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end(), cmp);
        map<int, int> dp = {{0, 0}};
        for (const auto& job : jobs) {
            curr = prev(dp.upper_bound(job[0]))->second + job[2];
            if (curr > dp.rbegin()->second) {
                dp[job[1]] = curr;
            }
        }
        return dp.rbegin()->second;
    }
};