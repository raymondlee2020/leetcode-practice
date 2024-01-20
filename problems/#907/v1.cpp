class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9 + 7, n = arr.size(), ret = 0;
        long tmp;
        vector<int> l(n), r(n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[i] < arr[s.top()]) s.pop();
            l[i] = s.empty() ? (i + 1) : (i - s.top());
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; --i) {
            // for two equal nums, only one of them can contribute to the interval contains them
            while (!s.empty() && arr[i] <= arr[s.top()]) s.pop();
            r[i] = s.empty() ? (n - i) : (s.top() - i);
            s.push(i);
        }
        for (int i = 0; i < n; ++i) {
            tmp = (l[i] * r[i]) % MOD;
            tmp = (tmp * arr[i]) % MOD;
            ret = (ret + tmp) % MOD;
        }
        return ret;
    }
};