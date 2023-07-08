class Solution {
public:
    int n;

    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1 || k == n) {
            return 0;
        }
        for (int i = 0; i < n - 1; ++i) {
            weights[i] += weights[i + 1];
        }
        sort(weights.begin(), weights.end() - 1);
        long long ret = 0;
        for (int i = 0; i < k - 1; ++i) {
            ret += weights[n - 2 - i] - weights[i];
        }
        return ret;
    }
};