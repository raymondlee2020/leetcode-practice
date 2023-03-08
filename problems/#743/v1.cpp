class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        }
    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto edge: times) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<int> visited(n + 1, -1);
        // {node, cost}
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        pq.push({k, 0});
        pair<int, int> curr;
        while (!pq.empty()) {
            curr = pq.top();
            pq.pop();
            if (visited[curr.first] >= 0) {
                continue;
            }
            visited[curr.first] = curr.second;
            for (auto neighbor: graph[curr.first]) {
                pq.push({neighbor.first, curr.second + neighbor.second});
            }
        }
        int ret = -1;
        int missed = 0;
        for (auto cost: visited) {
            if (cost == -1) {
                ++missed;
                continue;
            }
            if (cost > ret) {
                ret = cost;
            }
        }
        return (missed - 1) > 0 ? -1 : ret;
    }
};