class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        int s = 1, idx = 0;
        for (int i = 0; i < k; ++i) {
            s *= (n - i);
            s /= (i + 1);
        }
        vector<vector<int>> ret(s);
        vector<int> path;
        solve(ret, idx, path, n, k);
        return ret;
    }

    void solve(vector<vector<int>>& ret, int& idx, vector<int>& path, int n, int k) {
        if (k == 0) {
            ret[idx++] = path;
            return;
        }
        if (n < 1) {
            return;
        }
        path.push_back(n);
        solve(ret, idx, path, n - 1, k - 1);
        path.pop_back();
        solve(ret, idx, path, n - 1, k);
    }
};