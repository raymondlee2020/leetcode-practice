class UnionFind {
public:
    vector<int> parents;
    int count;

    UnionFind(int n) {
        parents = vector<int>(n);
        iota(parents.begin(), parents.end(), 0);
        count = n;
    }

    int _find(int i) {
        return i == parents[i] ? i : (parents[i] = _find(parents[i]));
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

    bool _isConnected(int i, int j) {
        return _find(i) == _find(j);
    }
};

class Solution {
public:
    int e;

    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        e = edges.size();
        vector<int> critical, pscritical;
        for (int i = 0; i < e; ++i) {
            cout << i << " ";
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), cmp);
        int mstw = findMST(n, edges, -1, -1);
        for (int i = 0; i < e; ++i) {
            if (findMST(n, edges, i, -1) > mstw) {
                critical.push_back(edges[i][3]);
            } else if (findMST(n, edges, -1, i) == mstw) {
                pscritical.push_back(edges[i][3]);
            }
        }
        return {critical, pscritical};
    }

    int findMST(int n, vector<vector<int>>& edges, int exclude, int include) {
        UnionFind uf(n);
        int wsum = 0;
        if (include != -1) {
            wsum += edges[include][2];
            uf._union(edges[include][0], edges[include][1]);
        }
        for (int i = 0; i < e; ++i) {
            if (i == exclude || uf._isConnected(edges[i][0], edges[i][1])) {
                continue;
            }
            uf._union(edges[i][0], edges[i][1]);
            wsum += edges[i][2];
        }
        return uf.count == 1 ? wsum : INT_MAX;
    }
};