class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size(), idx;
        vector<int> ret(n, 0);
        for (int i = n - 2; i >= 0; --i) {
            idx = i + 1;
            while (temperatures[idx] <= temperatures[i]) {
                if (ret[idx] == 0) {
                    idx = i;
                    break;
                }
                idx += ret[idx];
            }
            ret[i] = idx - i;
        }
        return ret;
    }
};