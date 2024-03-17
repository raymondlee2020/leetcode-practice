class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) return {newInterval};
        bool inserted = false;
        vector<vector<int>> ret;
        vector<int> mergedInterval = newInterval;
        for (const auto& interval: intervals) {
            if (interval[1] < mergedInterval[0]) {
                ret.push_back(interval);
            } else if (interval[0] > mergedInterval[1]) {
                if (!inserted) ret.push_back(mergedInterval), inserted = true;
                ret.push_back(interval);
            } else {
                mergedInterval[0] = min(mergedInterval[0], interval[0]);
                mergedInterval[1] = max(mergedInterval[1], interval[1]);
            }
        }
        if (!inserted) ret.push_back(mergedInterval);
        return ret;
    }
};