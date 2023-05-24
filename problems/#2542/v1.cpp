class Solution {
public:
    struct cmp {
        bool operator() (pair<int, int> a, pair<int, int> b) { 
            return a.second < b.second;
        }
    };

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = {nums1[i], nums2[i]};
        }
        sort(nums.begin(), nums.end(), cmp());
        long long ret, acc = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = n - 1; i > n - k - 1; --i) {
            pq.push(nums[i].first);
            acc += nums[i].first;
        }
        ret = acc * nums[n - k].second;
        int tmp;
        for (int i = n - k - 1; i >= 0; --i) {
            tmp = pq.top();
            pq.pop();
            acc -= tmp;
            pq.push(nums[i].first);
            acc += nums[i].first;
            ret = max(ret, acc * nums[i].second);
        }
        return ret;
    }
};