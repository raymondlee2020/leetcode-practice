class Solution {
public:
    int n;

    int smallestDistancePair(vector<int>& nums, int k) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = nums[n - 1] - nums[0], mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (isLargeOrEqualThanK(mid, nums, k)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    bool isLargeOrEqualThanK(int num, vector<int>& nums, int k) {
        int cnt = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && (nums[j] - nums[i]) <= num) {
                ++j;
            }
            cnt += (j - i - 1);
        }
        return cnt >= k;
    }
};