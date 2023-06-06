class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if (arr.size() == 2) {
            return true;
        }
        sort(arr.begin(), arr.end());
        int n = arr.size(), diff = arr[1] - arr[0];
        for (int slow = 1, fast = 2; fast < n; ++slow, ++fast) {
            if ((arr[fast] - arr[slow]) != diff) {
                return false;
            };
        }
        return true;
    }
};