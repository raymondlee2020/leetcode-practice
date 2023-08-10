class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n - 1, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int dev = l, deved_mid;
        l = 0, r = n;
        while (l < r) {
            mid = l + (r - l) / 2;
            deved_mid = (mid + dev) % n;
            if (nums[deved_mid] == target) {
                return deved_mid;
            } else if (nums[deved_mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};