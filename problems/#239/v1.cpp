class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret(n - k + 1);
        deque<int> dq;
        for (int i = 0; i < k - 1; ++i) {
            put(dq, nums, i, k);
        }
        for (int i = k - 1; i < n; ++i) {
            put(dq, nums, i, k);
            ret[i - k + 1] = nums[dq.front()];
        }
        return ret;
    }

    void put(deque<int>& dq, vector<int>& nums, int idx, int k) {
        while (dq.size() > 0 && dq.front() <= idx - k) {
            dq.pop_front();
        }
        while (dq.size() > 0 && nums[idx] > nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(idx);
    }
};