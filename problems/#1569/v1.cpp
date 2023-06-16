class Solution {
public:
    long long MOD;
    vector<vector<long long>> ncr;

    int numOfWays(vector<int>& nums) {
        MOD = 1000000007;
        int n = nums.size();
        ncr.resize(n + 1);
        for (int i = 0; i < n + 1; ++i) {
            ncr[i] = vector<long long>(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
            }
        }
        return (solve(nums) - 1) % MOD;
    }

    long long solve(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return 1;
        }
        vector<int> l, r;
        for (int i = 1; i < n; ++i) {
            (nums[i] < nums[0]) ? l.push_back(nums[i]) : r.push_back(nums[i]);
        }
        return (ncr[n - 1][l.size()] * solve(l) % MOD) * solve(r) % MOD;
    }
};