class UnionFind {
public:
    vector<int> parents;
    int count;

    UnionFind(int n) {
        parents = vector<int>(n + 1);
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (uf._isConnected(i, j)) {
                    continue;
                }
                if (isConnected[i][j] == 1) {
                    uf._union(i, j);
                }
            }
        }
        return uf.count;
    }
};