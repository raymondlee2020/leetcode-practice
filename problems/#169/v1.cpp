class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> cnts;
        for (const auto num: nums) {
            if (cnts.find(num) == cnts.end()) {
                cnts[num] = 0;
            }
            cnts[num]++;
        }
        int maxNum = 0;
        int maxCnt = 0;
        for (const auto [num, cnt]: cnts) {
            if (cnt > maxCnt) {
                maxNum = num;
                maxCnt = cnt;
            }
        }
        return maxNum;
    }
};