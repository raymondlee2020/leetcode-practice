class Solution {
public:
    vector<int> parents;

    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parents = vector<int>(n);
        int es = edgeList.size(), qs = queries.size();
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
        for (int i = 0; i < qs; ++i) {
            queries[i].push_back(i);
        }
        sort(edgeList.begin(), edgeList.end(), cmp);
        sort(queries.begin(), queries.end(), cmp);
        vector<bool> ret(qs, false);
        int i = 0;
        for (const auto& query: queries) {
            for (; i < es && edgeList[i][2] < query[2]; ++i) {
                _union(edgeList[i][0], edgeList[i][1]);
            }
            ret[query[3]] = _isConnected(query[0], query[1]);
        }
        return ret;
    }

    int _find(int i) {
        return i == parents[i] ? i : (parents[i] = _find(parents[i]));
    }

    void _union(int i, int j) {
        int iroot = _find(i), jroot = _find(j);
        if (iroot == jroot) {
            return;
        }
        parents[iroot] = jroot;
    }

    bool _isConnected(int i, int j) {
        return _find(i) == _find(j);
    }
};