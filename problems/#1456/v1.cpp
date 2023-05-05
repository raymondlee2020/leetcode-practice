class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int> vidxs = getVowelIdxs(s);
        if (vidxs.size() == 0) {
            return 0;
        }
        int l = 0, r = 0, curr = 0, ret = 0;
        while (r < vidxs.size()) {
            while (vidxs[r] - vidxs[l] + 1 > k) {
                ++l, --curr;
            }
            ++curr;
            ret = max(ret, curr);
            ++r;
        }
        return ret;
    }

    vector<int> getVowelIdxs(string s) {
        vector<int> ret;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                ret.push_back(i);
            }
        }
        return ret;
    }
};