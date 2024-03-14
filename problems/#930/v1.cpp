class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), ret = 0, lo = -1, ro = 0;
        queue<int> q;
        while (ro < n && q.size() < goal) {
            if (nums[ro] == 1) q.push(ro);
            ++ro;
        }
        if (q.size() != goal) return 0;
        while (ro < n) {
            if (nums[ro] == 1) {
                ret += goal == 0 ? (ro - lo) * (ro - lo - 1) / 2 : (q.front() - lo) * (ro - q.back());
                q.push(ro), lo = q.front(), q.pop();
            }
            ++ro;
        }
        ret += goal == 0 ? (ro - lo) * (ro - lo - 1) / 2 : (q.front() - lo) * (ro - q.back());
        return ret;
    }
};