class Solution {
public:
    int countOrders(int n) {
        int MOD = 1e9 + 7;
        long ret = 1;
        for (int i = n; i > 1; --i) {
            ret = (ret * i * ((2 * i) - 1)) % MOD;
        }
        return ret;
    }
};