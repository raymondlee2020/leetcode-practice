class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int prev2 = 1, prev1 = 1, curr;
        while (--n > 0) {
            curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};