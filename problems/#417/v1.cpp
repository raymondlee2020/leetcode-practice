class Solution {
public:
    vector<vector<bool>> visited;
    int m;
    int n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.size() == 0) {
            return {};
        }
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        // to Pacific Ocean
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        // left side
        for (int i = 0; i < m; ++i) {
            dfs(make_pair(i, 0), make_pair(i, 0), heights, pac);
        }
        // top side
        for (int i = 0; i < n; ++i) {
            dfs(make_pair(0, i), make_pair(0, i), heights, pac);
        }
        // to Atlantic Ocean
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        // right side
        for (int i = 0; i < m; ++i) {
            dfs(make_pair(i, (n - 1)), make_pair(i, (n - 1)), heights, atl);
        }
        // down side
        for (int i = 0; i < n; ++i) {
            dfs(make_pair((m - 1), i), make_pair((m - 1), i), heights, atl);
        }
        vector<vector<int>> ret;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pac[i][j] && atl[i][j]) {
                    ret.push_back({i, j});
                }
            }
        }
        return ret;
    }

    void dfs(pair<int, int> from, pair<int, int> to, vector<vector<int>>& heights, vector<vector<bool>>& ocean) {
        if (to.first < 0 || to.first >= m || to.second < 0 || to.second >= n) {
            return;
        }
        if (heights[from.first][from.second] > heights[to.first][to.second]) {
            return;
        }
        if (visited[to.first][to.second]) {
            return;
        }
        visited[to.first][to.second] = true;
        ocean[to.first][to.second] = true;
        dfs(to, make_pair(to.first - 1, to.second), heights, ocean);
        dfs(to, make_pair(to.first, to.second - 1), heights, ocean);
        dfs(to, make_pair(to.first + 1, to.second), heights, ocean);
        dfs(to, make_pair(to.first, to.second + 1), heights, ocean);
    }
};