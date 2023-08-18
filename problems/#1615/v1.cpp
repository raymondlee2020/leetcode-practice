class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degrees(n, 0);
        for (const auto& cs: roads) {
            ++degrees[cs[0]], ++degrees[cs[1]];
        }
        int fm = 0, sm = 0;
        for (const auto& degree: degrees) {
            if (degree > fm) {
                sm = fm;
                fm = degree;
            } else if (degree > sm && degree < fm) {
                sm = degree;
            }
        }
        int fmcnt = 0, smcnt = 0;
        for (const auto& degree: degrees) {
            if (degree == fm) {
                ++fmcnt;
            } else if (degree == sm) {
                ++smcnt;
            }
        }
        int ret, interedgecnt = 0, maxinteredgecnt;
        if (fmcnt > 1) {
            ret = 2 * fm, maxinteredgecnt = fmcnt * (fmcnt - 1) / 2;
            for (const auto& cs: roads) {
                if (degrees[cs[0]] == fm && degrees[cs[1]] == fm) {
                    ++interedgecnt;
                }
            }
        } else {
            ret = fm + sm, maxinteredgecnt = smcnt;
            for (const auto& cs: roads) {
                if ((degrees[cs[0]] == fm && degrees[cs[1]] == sm) || (degrees[cs[0]] == sm && degrees[cs[1]] == fm)) {
                    ++interedgecnt;
                }
            }
        }
        if (interedgecnt == maxinteredgecnt) {
            --ret;
        }
        return ret;
    }
};