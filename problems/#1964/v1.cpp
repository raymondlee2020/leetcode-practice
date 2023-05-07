class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int len, n = obstacles.size();
        vector<int> dp, ret(n);
        for (int i = 0; i < n; ++i) {
            len = distance(dp.begin(), lower_bound(dp.begin(), dp.end(), obstacles[i] + 1));
            if (len == dp.size()) {
                dp.push_back(obstacles[i]);
            } else {
                dp[len] = obstacles[i];
            }
            ret[i] = len + 1;
        }
        return ret;
    }
};