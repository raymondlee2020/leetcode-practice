class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        vector<vector<int>> visited(n, vector<int>(2, INT_MAX));
        vector<int> curr;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int newprice, newstep;
        for (const auto& flight: flights) graph[flight[0]].push_back({flight[1], flight[2]});
        // {PRICE, STEP, CITY}
        pq.push({0, 0, src});
        while (!pq.empty()) {
            curr = pq.top(), pq.pop();
            if (curr[2] == dst) return curr[0];
            if (curr[1] > k) continue;
            newstep = curr[1] + 1;
            for (const auto& adj: graph[curr[2]]) {
                newprice = curr[0] + adj.second;
                if (newprice >= visited[adj.first][0] && newstep >= visited[adj.first][1]) continue;
                if (newprice < visited[adj.first][0] && newstep < visited[adj.first][1]) {
                    visited[adj.first][0] = newprice;
                    visited[adj.first][1] = newstep;
                }
                pq.push({newprice, newstep, adj.first});
            }
        }
        return -1;
    }
};