class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size(), ret = 0;
        vector<int> prev = intervals[0];
        for (int i = 1; i < n; ++i) {
                if (prev[1] > intervals[i][0]) {
                    ++ret;
                } else {
                    prev = intervals[i];
                }
        }
        return ret;
    }
};