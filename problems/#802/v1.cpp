class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0), ret;
        for (int i = 0; i < n; ++i) {
            solve(ret, graph, visited, i);
        }
        sort(ret.begin(), ret.end());
        return ret;
    }

    bool solve(vector<int>& ret, vector<vector<int>>& graph, vector<int>& visited, int curr) {
        if (visited[curr] > 0) {
            return visited[curr] > 1 ? true : false;
        }
        bool incycle = false;
        visited[curr] = 2;
        for (int adj: graph[curr]) {
            incycle |= solve(ret, graph, visited, adj);
        }
        visited[curr] = incycle ? 3 : 1;
        if (!incycle) {
            ret.push_back(curr);
        }
        return incycle;
    }
};