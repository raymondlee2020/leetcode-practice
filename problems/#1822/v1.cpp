class Solution {
public:
    int arraySign(vector<int>& nums) {
        int prod = 1;
        for (const auto& num: nums) {
            if (num == 0) {
                return 0;
            }
            prod ^= num;
        }
        return (prod >= 0) ? 1 : -1;
    }
};