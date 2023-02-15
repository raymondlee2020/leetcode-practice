class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> states(numCourses, 0);
        vector<vector<int>> prereqs(numCourses);
        for (const auto p: prerequisites) {
            prereqs[p[0]].push_back(p[1]);
        }
        bool valid;
        for (int i = 0; i < numCourses; ++i) {
            valid = dfs(i, states, prereqs);
            if (!valid) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int course, vector<int>& states, vector<vector<int>>& prereqs) {
        if (states[course] == 2) {
            return true;
        }
        if (states[course] == 1) {
            return false;
        }
        ++states[course];
        bool valid;
        for (const auto p: prereqs[course]) {
            valid = dfs(p, states, prereqs);
            if (!valid) {
                return false;
            }
        }
        ++states[course];
        return true;
    }
};