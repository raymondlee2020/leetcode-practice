class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int maxNum = 0;
        int minNum = 0;
        for (const auto num: nums) {
            if (num > maxNum) {
                maxNum = num;
            }
            if (num < minNum) {
                minNum = num;
            }
        }
        int bucketSize = (-1) * minNum + maxNum + 1;
        int *bucket = new int[bucketSize];
        memset(bucket, 0, bucketSize * sizeof(int));
        for (const auto num: nums) {
            bucket[num - minNum]++;
        }
        int pv = 0;
        for (int pv = 0, idx = 0;pv < bucketSize;pv++) {
            while(bucket[pv]){
                nums[idx++] = pv + minNum;
                bucket[pv]--;
            }
        }
        delete[] bucket;
        return nums;
    }
};