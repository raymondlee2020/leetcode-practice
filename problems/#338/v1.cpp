class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n + 1);
        int tmp = 1;
        ret[0] = 0;
        for (int i = 1; i <= n; ++i) {
            if (i == tmp * 2) {
                tmp *= 2;
            }
            ret[i] = ret[i % tmp] + 1;
        }
        return ret;
    }
};