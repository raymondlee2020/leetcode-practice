class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> cnt;
        for (char c: s) {
            ++cnt[c];
        }
        int ret = 0, freq;
        unordered_map<int, bool> gm;
        unordered_map<int, int> coll;
        for (const auto& [c, n]: cnt) {
            ret += (n - findGoodFreq(gm, coll, n));
        }
        return ret;
    }

    int findGoodFreq(unordered_map<int, bool>& gm, unordered_map<int, int>& coll, int from) {
        if (from == 0 || !gm[from]) {
            gm[from] = true;
            return from;
        }
        return coll[from] = coll.find(from) == coll.end() ? findGoodFreq(gm, coll, from - 1) : findGoodFreq(gm, coll, coll[from]);
    }
};