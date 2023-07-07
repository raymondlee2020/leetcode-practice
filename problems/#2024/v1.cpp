class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ret = 0, n = answerKey.size(), t = 0, f = 0, tl = 0, fl = 0, r;
        for (r = 0; r < n; ++r) {
            if (answerKey[r] == 'T') {
                if (++t > k) {
                    ret = max(ret, r - fl);
                    while (t > k) {
                        if (answerKey[fl++] == 'T') {
                            --t;
                        }
                    }
                }
            } else {
                if (++f > k) {
                    ret = max(ret, r - tl);
                    while (f > k) {
                        if (answerKey[tl++] == 'F') {
                            --f;
                        }
                    }
                }

            }
        }
        ret = max(ret, r - tl);
        ret = max(ret, r - fl);
        return ret;
    }
};