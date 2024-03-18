class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size(), curr, ret = 1;
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        curr = points[0][1];
        for (int i = 1; i < n; ++i) {
            if (points[i][0] > curr) ++ret, curr = points[i][1];
        }
        return ret;
    }
};