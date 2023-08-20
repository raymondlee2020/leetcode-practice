class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> graph(n + m);
        vector<int> indegree(n + m, 0);
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                continue;
            }
            graph[n + group[i]].push_back(i);
            ++indegree[i];
        }
        int iidx, jidx;
        for (int i = 0; i < n; ++i) {
            for(int j : beforeItems[i]) {
                iidx = group[i] == -1 ? i : n + group[i];
                jidx = group[j] == -1 ? j : n + group[j];
                // same group, ingroup order
                if(iidx == jidx) { 
                    graph[j].push_back(i);
                    ++indegree[i];
                // not in smae group, outgroup order
                } else {
                    graph[jidx].push_back(iidx);
                    ++indegree[iidx];
                }
            }
        }
        vector<int> ret;
        for (int i = 0; i < n + m; ++i) {
            if (indegree[i] == 0) {
                dfs(ret, graph, indegree, n, i);
            }
        }
        return ret.size() == n ? ret : vector<int>(0);
    }

    void dfs(vector<int>& ret, vector<vector<int>>& graph, vector<int>& indegree, int n, int curr) {
        if (curr < n) {
            ret.push_back(curr);
        }
        indegree[curr] = -1;
        for(auto adj: graph[curr]) {
            indegree[adj]--;
            if (indegree[adj] == 0) {
                dfs(ret, graph, indegree, n, adj);
            }
        }
    }
};