class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int ans = min(height[l], height[r]) * (r - l);
        while (l != r) {
            if (height[l] > height[r]) {
                r--;
            } else {
                l++;
            }
            ans = max(ans, min(height[l], height[r]) * (r - l));
        }
        return ans;
    }
};