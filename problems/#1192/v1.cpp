class Solution {
public:
    vector<vector<int>> graph;
    vector<int> visited;
    int ts;

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph = vector<vector<int>>(n);
        visited = vector<int>(n, INT_MAX);
        for (auto conn: connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        ts = 0;
        vector<vector<int>> ret;
        tarjan(0, -1, ret);
        return ret;
    }

    int tarjan(int curr, int parent, vector<vector<int>>& ret) {
        int min_curr = visited[curr] = ++ts;
        for (auto neighbor: graph[curr]) {
            if (visited[neighbor] == INT_MAX) {
                int min_neighbor = tarjan(neighbor, curr, ret);
                min_curr = min(min_curr, min_neighbor);
                if (visited[curr] < min_neighbor) {
                    ret.push_back({curr, neighbor});
                }
            } else if (neighbor != parent) {
                min_curr = min(min_curr, visited[neighbor]);
            }
        }
        return min_curr;
    }
};