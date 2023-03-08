class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for (auto num: nums) {
            ++m[num];
        }
        vector<pair<int, int>> tmp;
        for (auto entry: m) {
            tmp.push_back(entry);
        }
        sort(tmp.begin(), tmp.end(), cmp);
        vector<int> ret;
        for (int i = 0; i < k; ++i) {
            ret.push_back(tmp[i].first);
        }
        return ret;
    }
};