class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int steps = (m + n) / 2 + 1, i = 0, j = 0, prev, curr;
        double ret;
        while (steps > 0 && i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                prev = curr;
                curr = nums1[i++];
            } else {
                prev = curr;
                curr = nums2[j++];
            }
            --steps;
        }
        if (steps > 0) {
            if (i == m) {
                while (steps > 0) {
                    prev = curr;
                    curr = nums2[j++];
                    --steps;
                }
            } else {
                while (steps > 0) {
                    prev = curr;
                    curr = nums1[i++];
                    --steps;
                }
            }
        }
        ret = curr;
        if ((m + n) % 2 == 0) {
            ret += prev;
            ret /= 2;
        }
        return ret;
    }
};