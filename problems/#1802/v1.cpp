class Solution {
public:
    int shortSide, longSide;

    int maxValue(int n, int index, int maxSum) {
        shortSide = min(index + 1, n - index);
        longSide = max(index + 1, n - index);
        int mid, l = 0, r = maxSum + 1;
        long tmp;
        while (l < r) {
            mid = l + (r - l) / 2;
            tmp = arrSum(mid);
            if (tmp == maxSum) {
                return mid;
            } else if (tmp > maxSum) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l - 1;
    }

    long arrSum(int peak) {
        long ret = (long) (2 * peak) * peak / 2;
        if (peak < longSide) {
            ret += longSide - peak;
        } else {
            ret -= (long) (peak - longSide + 1) * (peak - longSide) / 2;
        }
        if (peak < shortSide) {
            ret += shortSide - peak;
        } else {
            ret -= (long) (peak - shortSide + 1) * (peak - shortSide) / 2;
        }
        return ret;
    }
};