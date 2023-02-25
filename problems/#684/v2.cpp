class DSU {
    vector<int> par, rank;
public:
    DSU(int n) : par(n), rank(n) {
        iota(begin(par), end(par), 0);
    }
    int find(int x) {
        if (x == par[x]) {
            return x;
        }
        return par[x] = find(par[x]);
    }
    bool do_union(int x, int y) {
        int xp = find(x);
        int yp = find(y);
        if (xp == yp) {
            return false;
        }
        if (rank[xp] > rank[yp]) {
            par[yp] = par[xp];
        } else if (rank[yp] > rank[xp]) {
            par[xp] = par[yp];
        } else {
            par[xp] = yp;
            rank[yp]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size() + 1);
        vector<int> ret;
        for(const auto edge : edges) {
            if (!dsu.do_union(edge[0], edge[1])) {
                ret = edge;
            }
        }
        return ret;
    }
};