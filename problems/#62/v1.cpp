class Solution {
public:
    int uniquePaths(int m, int n) {
        int p = m > n ? (n - 1) : (m - 1), q = m + n - 2;
        double ret = 1;
        for (int i = 1; i <= p; ++i) {
            ret *= (q - p + i);
            ret /= i;
        }
        return (int) ret;
    }
};