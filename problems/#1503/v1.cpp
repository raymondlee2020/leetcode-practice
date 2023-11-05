class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ret = INT_MIN;
        for (const auto& pos: left) {
            ret = max(ret, pos);
        }
        for (const auto& pos: right) {
            ret = max(ret, n - pos);
        }
        return ret;
    }
};