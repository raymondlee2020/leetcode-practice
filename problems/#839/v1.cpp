class Solution {
public:
    int n, m, count;
    vector<int> parents;

    int numSimilarGroups(vector<string>& strs) {
        n = strs.size();
        m = strs[0].size();
        count = n;
        parents = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isSimilar(strs[i], strs[j])) {
                    _union(i, j);
                }
            }
        }
        return count;
    }

    bool isSimilar(string str1, string str2) {
        int diff = 0;
        for (int i = 0; i < m; ++i) {
            if (str1[i] != str2[i]) {
                ++diff;
            }
        }
        return diff == 0 || diff == 2;
    }

    int _find(int i) {
        if (parents[i] != i) {
            parents[i] = _find(parents[i]);
        }
        return parents[i];
    }

    void _union(int i, int j) {
        int iroot = _find(i);
        int jroot = _find(j);
        if (iroot == jroot) {
            return;
        }
        parents[iroot] = jroot;
        --count;
    }
};