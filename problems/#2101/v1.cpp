class Solution {
public:
    int n;

    int maximumDetonation(vector<vector<int>>& bombs) {
        n = bombs.size();
        int ret = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            visited = vector<bool>(n, false);
            ret = max(ret, dfs(i, bombs, visited));
        }
        return ret;
    }

    int dfs(int curr, vector<vector<int>>& bombs, vector<bool>& visited) {
        int ret = 1;
        visited[curr] = true;
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && canDetonat(bombs, curr, i)) {
                ret += dfs(i, bombs, visited);
            }
        }
        return ret;
    }

    bool canDetonat(vector<vector<int>>& bombs, int i , int j) {
        double dis = pow(pow(bombs[i][0] - bombs[j][0], 2) + pow(bombs[i][1] - bombs[j][1], 2), 0.5);
        return bombs[i][2] >= dis;
    }
};