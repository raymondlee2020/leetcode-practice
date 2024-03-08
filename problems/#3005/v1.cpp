class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int ret = 0, maxfreq = 0;
        for (const auto& num: nums) maxfreq = max(maxfreq, ++cnt[num]);
        for (const auto& [k, v]: cnt) {
            if (v == maxfreq) ret += maxfreq;
        }
        return ret;
    }
};