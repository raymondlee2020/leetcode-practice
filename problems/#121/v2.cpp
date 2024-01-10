class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0, n = prices.size(), l = 0, r = 0;
        for (int i = 0; i < n; ++i) {
            if (prices[i] > prices[r]) {
                r = i;
                ret = max(ret, prices[r] - prices[l]);
            } else if (prices[i] < prices[l]) {
                l = r = i;
            }
        }
        return ret;
    }
};