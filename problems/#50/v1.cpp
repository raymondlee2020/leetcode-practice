class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
            n = abs(n);
        }
        double ret = 1;
        while (n > 0) {
            if (n & 1 == 1) {
                ret *= x;
            }
            x *= x;
            n >>= 1;
        }
        return ret;
    }
};