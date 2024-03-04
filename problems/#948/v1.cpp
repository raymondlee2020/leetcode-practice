class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ret = 0, curr = 0, l = 0, r = tokens.size() - 1;
        sort(tokens.begin(), tokens.end());
        if (r == -1 || tokens[0] > power) return 0;
        while (l <= r) {
            if (tokens[l] <= power) {
                ++curr, power -= tokens[l++];
                ret = max(ret, curr);
            } else {
                --curr, power += tokens[r--];
            }
        }
        return ret;
    }
};