class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generateNextSym(ret, "", n, 0, 0);
        return ret;
    }

    void generateNextSym(vector<string>& ret, string curr, int bound, int lcnt, int rcnt) {
        if (rcnt == bound) {
            ret.push_back(curr);
            return;
        }
        if (lcnt < bound) {
            generateNextSym(ret, curr + "(", bound, lcnt + 1, rcnt);
        }
        if (rcnt < lcnt) {
            generateNextSym(ret, curr + ")", bound, lcnt, rcnt + 1);
        }
    }
};