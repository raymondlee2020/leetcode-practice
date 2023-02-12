class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        int dp_i_1 = 1, dp_i_2 = 0;
        for (int i = 1; i < n; ++i) {
            dp_i_2 = dp_i_1 + dp_i_2;
            swap(dp_i_1, dp_i_2);
        }
        return dp_i_1;
    }
};