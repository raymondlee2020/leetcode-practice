class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ret = 0, curr = 0;
        for (const auto& g: gain) {
            curr += g;
            ret = max(ret, curr);
        }
        return ret;
    }
};