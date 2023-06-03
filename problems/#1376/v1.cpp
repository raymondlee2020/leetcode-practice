class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> subordinates(n);
        for (int i = 0; i < n; ++i) {
            if (i == headID) {
                continue;
            }
            subordinates[manager[i]].push_back(i);
        }
        return dfs(headID, subordinates, informTime);
    }

    int dfs(int id, vector<vector<int>>& subordinates, vector<int>& informTime) {
        if (subordinates[id].size() == 0) {
            return informTime[id];
        }
        int ret = 0;
        for (int subordinate: subordinates[id]) {
            ret = max(ret, dfs(subordinate, subordinates, informTime));
        }
        return informTime[id] + ret;
    }
};