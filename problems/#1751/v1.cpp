class Solution {
public:
    int n;
    vector<vector<int>> dp;

    struct cmp {
        bool operator() (const vector<int>& left, const vector<int>& right)
        {
            return left[0] < right[0];
        }
    };

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        n = events.size();
        dp = vector<vector<int>>(n, vector<int>(k + 1, -1));
        return solve(events, k, 0);
    }

    int solve(vector<vector<int>>& events, int k, int curr) {
        if (curr == n || k == 0) {
            return 0;
        }
        if (dp[curr][k] != -1) {
            return dp[curr][k];
        }
        vector<int> tmp = {events[curr][1]};
        int next = upper_bound(events.begin() + curr + 1, events.end(), tmp, cmp()) - events.begin();
        return dp[curr][k] = max(solve(events, k, curr + 1), events[curr][2] + solve(events, k - 1, next));
    }
};