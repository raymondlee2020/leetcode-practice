class Solution {
public:
    vector<bool> visited;
    vector<int> flag;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        visited = vector<bool>(n, false);
        flag = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!dfs(i, flag[i], graph)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int node, int expect, vector<vector<int>>& graph) {
        if (visited[node]) {
            return flag[node] == expect;
        }
        visited[node] = true;
        expect = expect == 0 ? 1 : expect;
        flag[node] = expect;
        for (const int neighbor: graph[node]) {
            if (!dfs(neighbor, (-1) * expect, graph)) {
                return false;
            }
        }
        return true;
    }
};