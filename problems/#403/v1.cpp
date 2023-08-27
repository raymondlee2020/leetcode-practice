class Solution {
public:
    int dest;
    unordered_map<int, bool> river;
    unordered_map<int, unordered_map<int, bool>> dp;

    bool canCross(vector<int>& stones) {
        dest = stones[stones.size() - 1];
        for (int pos: stones) {
            river[pos] = true;
        }
        return river[stones[0] + 1] && solve(stones[0] + 1, 1);
    }

    bool solve(int curr, int lastjump) {
        if (curr > dest) {
            return false;
        }
        if (curr == dest) {
            return true;
        }
        if (dp.find(curr) != dp.end() && dp[curr].find(lastjump) != dp[curr].end()) {
            return dp[curr][lastjump];
        }
        bool ret = false;
        if (lastjump - 1 > 0 && river[curr + lastjump - 1]) {
            ret |= solve(curr + lastjump - 1, lastjump - 1);
        }
        if (river[curr + lastjump]) {
            ret |= solve(curr + lastjump, lastjump);
        }
        if (river[curr + lastjump + 1]) {
            ret |= solve(curr + lastjump + 1, lastjump + 1);
        }
        return dp[curr][lastjump] = ret;
    }
};