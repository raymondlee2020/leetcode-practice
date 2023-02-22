class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> confid(n, 0);
        for (const auto relationship: trust) {
            ++confid[relationship[1] - 1];
            --confid[relationship[0] - 1];
        }
        for (int i = 0; i < n; ++i) {
            if (confid[i] == (n - 1)) {
                return (i + 1);
            }
        }
        return -1;
    }
};