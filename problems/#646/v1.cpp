class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b){
            return a[1] < b[1];
        });
        int n = pairs.size(), prev = 0, ret = 1;
        for (int i = 1; i < n; ++i) {
            if (pairs[i][0] > pairs[prev][1]) {
                ++ret;
                prev = i;
            }
        }
        return ret;
    }
};