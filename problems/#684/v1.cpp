class Solution {
public:
    vector<bool> visited;
    unordered_set<int> cycle;
    vector<vector<int>> graph;
    int cycleStart;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        visited = vector<bool>((n + 1), false);
        graph = vector<vector<int>>((n + 1));
        cycleStart = -1;
        for (const auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(1, -1);
        vector<int> ret;
        for (int i = (n - 1); i >= 0; --i) {
            if (cycle.count(edges[i][0]) && cycle.count(edges[i][1])) {
                ret = edges[i];
                break;
            }
        }
        return ret;
    }

    void dfs(int curr, int par) {
        if (visited[curr]) {
            cycleStart = curr;
            return;
        }
        visited[curr] = true;
        for (const auto neighbor: graph[curr]) {
            if (neighbor == par) {
                continue;
            }
            if (cycle.empty()) {
                dfs(neighbor, curr);
            }
            if (cycleStart != -1) {
                cycle.insert(curr);
            }
            if (cycleStart == curr) {
                cycleStart = -1;
            }
        }
    }
};