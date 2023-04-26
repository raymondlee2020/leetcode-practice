class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int l = 1, r = x, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if ((x / mid) > mid) {
                l = mid + 1;
            } else if ((x / mid) < mid) {
                r = mid;
            } else {
                return mid;
            }
        }
        return l - 1;
    }
};