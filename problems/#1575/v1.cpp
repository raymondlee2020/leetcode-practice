class Solution {
public:
    int n, MOD;
    vector<vector<int>> dp;

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        if (abs(locations[start] - locations[finish]) > fuel) {
            return 0;
        }
        MOD = 1e9 + 7;
        n = locations.size();
        dp = vector<vector<int>>(n, vector<int>(fuel + 1, -1));
        return solve(locations, start, finish, fuel);
    }

    int solve(vector<int>& locations, int start, int finish, int fuel) {
        if (fuel < 0) {
            return 0;
        }
        if (dp[start][fuel] != -1) {
            return dp[start][fuel];
        }
        int ret = start == finish ? 1 : 0;
        for (int next = 0; next < n; ++next) {
            if (next == start) {
                continue;
            }
            ret = (ret + solve(locations, next, finish, fuel - abs(locations[start] - locations[next]))) % MOD;
        }
        return dp[start][fuel] = ret;
    }
};