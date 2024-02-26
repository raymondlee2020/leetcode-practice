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
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> divided;
        UnionFind uf(n);
        if (n == 1) return true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) return false;
            for (int d = 2; d * d <= nums[i]; ++d) {
                if (nums[i] % d != 0) continue;
                if (divided.find(d) != divided.end()) {
                    uf._union(i, divided[d]);
                } else {
                    divided[d] = i;
                }
                while (nums[i] % d == 0) nums[i] /= d;
            }
            if (nums[i] > 1) {
                if (divided.find(nums[i]) != divided.end()) {
                    uf._union(i, divided[nums[i]]);
                } else {
                    divided[nums[i]] = i;
                }
            }
        }
        return uf.count == 1;
    }
};