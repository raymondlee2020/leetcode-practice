class Solution {
public:
    int largestVariance(string s) {
        int ret = 0, tmp;
        bool has_b, first_b;
        unordered_set<char> cs(s.begin(), s.end());
        for (char a: cs) {
            for (char b: cs) {
                if (a == b) {
                    continue;
                }
                tmp = 0, has_b = false, first_b = false;
                for (char c: s) {
                    if (c == a) {
                        ++tmp;
                    } else if (c == b) {
                        has_b = true;
                        if (first_b && tmp >= 0) {
                            first_b = false;
                        } else if (--tmp < 0) {
                            first_b = true;
                            tmp = -1;
                        }
                    }
                    if (has_b) {
                        ret = max(ret, tmp);
                    }
                }
            }
        }
        return ret;
    }
};