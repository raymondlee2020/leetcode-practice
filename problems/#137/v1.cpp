class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0, cnt;
        for (int i = 0; i < 32; ++i) {
            cnt = 0;
            for (auto& num: nums) {
                cnt += (num >> i) & 1;
            }
            if (cnt % 3 != 0) {
                ret += 1 << i;
            }
        }
        return ret;
    }
};