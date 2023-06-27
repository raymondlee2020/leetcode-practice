class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (const int num: nums1) {
            pq.push({num + nums2[0], 0});
        }
        int n2 = nums2.size();
        vector<vector<int>> ret;
        pair<int, int> tmp;
        while (k-- > 0 && !pq.empty()) {
            tmp = pq.top();
            pq.pop();
            ret.push_back({tmp.first - nums2[tmp.second], nums2[tmp.second]});
            if (tmp.second + 1 < n2) {
                pq.push({tmp.first - nums2[tmp.second] + nums2[tmp.second + 1], tmp.second + 1});
            }
        }
        return ret;
    }
};