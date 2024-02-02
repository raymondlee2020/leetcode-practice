class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ret;
        int ld = cntDigit(low), hd = cntDigit(high), curr;
        for (int d = ld; d <= hd; ++d) {
            for (int i = 1; i <= (10 - d); ++i) {
                curr = seqNum(i, d);
                if (curr < low || curr > high) {
                    continue;
                }
                ret.push_back(curr);
            }
        }
        return ret;
    }

    int cntDigit(int num) {
        int ret = 0;
        while (num != 0) {
            ++ret;
            num /= 10;
        }
        return ret;
    }

    int seqNum(int start, int digit) {
        int ret = 0;
        while (digit-- > 0) {
            ret = (ret * 10) + start++;
        }
        return ret;
    }
};