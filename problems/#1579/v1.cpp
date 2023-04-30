class UnionFind {
public:
    vector<int> parents;
    int count;

    UnionFind(int n) {
        parents = vector<int>(n + 1);
        iota(parents.begin(), parents.end(), 0);
        count = n;
    }

    UnionFind(const UnionFind& uf) {
        parents = vector<int>(uf.parents.begin(), uf.parents.end());
        count = uf.count;
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

    UnionFind copy() {
        return UnionFind(*this);
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ret = 0;
        UnionFind uf1(n);
        for (const auto& edge: edges) {
            if (edge[0] == 3) {
                if (!uf1._isConnected(edge[1], edge[2])) {
                    uf1._union(edge[1], edge[2]);
                } else {
                    ++ret;
                }
            }
        }
        UnionFind uf2 = uf1.copy();
        for (const auto& edge: edges) {
            if (edge[0] == 1) {
                if (!uf1._isConnected(edge[1], edge[2])) {
                    uf1._union(edge[1], edge[2]);
                } else {
                    ++ret;
                }
            } else if (edge[0] == 2) {
                if (!uf2._isConnected(edge[1], edge[2])) {
                    uf2._union(edge[1], edge[2]);
                } else {
                    ++ret;
                }
            }
        }
        if (uf1.count != 1 || uf2.count != 1) {
            return -1;
        }
        return ret;
    }
};