class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> m;
        int n = grid.size();
        for (const auto row: grid) {
            ++m[row];
        }
        int ret = 0;
        vector<int> col;
        for (int j = 0; j < n; ++j) {
            col.clear();
            for (int i = 0; i < n; ++i) {
                col.push_back(grid[i][j]);
            }
            ret += m[col];
        }
        return ret;
    }
};