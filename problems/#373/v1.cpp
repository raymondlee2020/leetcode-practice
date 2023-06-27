class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>> pq;
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> tmp;
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                if (pq.size() < k) {
                    pq.push({nums1[i] + nums2[j], nums1[i], nums2[j]});
                } else {
                    tmp = pq.top();
                    if (nums1[i] + nums2[j] > tmp[0]) {
                        break;
                    }
                    pq.pop();
                    pq.push({nums1[i] + nums2[j], nums1[i], nums2[j]});
                }
            }
        }
        vector<vector<int>> ret;
        while (!pq.empty()) {
            tmp = pq.top();
            pq.pop();
            ret.push_back({tmp[1], tmp[2]});
        }
        return ret;
    }
};