class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        int e = edges.size();
        for (int i = 0; i < e; ++i) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> memo(n, 0.0);
        queue<int> q;
        int curr;
        double prob;
        memo[start] = 1.0;
        q.push(start);
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            for (const auto& edge: graph[curr]) {
                prob = memo[curr] * edge.second;
                if (prob <= memo[edge.first]) {
                    continue;
                }
                memo[edge.first] = prob;
                q.push(edge.first);
            }
        }
        return memo[end];
    }
};