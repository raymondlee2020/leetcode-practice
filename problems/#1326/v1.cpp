class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }

    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> intvls(n + 1);
        for (int i = 0; i <= n; ++i) {
            intvls[i] = {i - ranges[i], i + ranges[i]};
        }
        sort(intvls.begin(), intvls.end(), cmp);
        int ret = 0, prev = 0, curr = 0;
        while (prev < n) {
            for (const auto& intvl: intvls) {
                if (intvl[0] <= prev) {
                    curr = intvl[1];
                    break;
                }
            }
            if (curr == prev) {
                return -1;
            }
            prev = curr;
            ++ret;
        }
        return ret;
    }
};