class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ret = 0, tmp;
        while (a != 0 || b != 0 || c != 0) {
            tmp = c & 1;
            if (tmp == 1) {
                ret += ((a & 1) + (b & 1) == 0) ? 1 : 0;
            } else {
                ret += ((a & 1) + (b & 1));
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return ret;
    }
};