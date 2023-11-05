class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size(), cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[0] < arr[i]) {
                swap(arr[0], arr[i]);
                cnt = 0;
            }
            if (++cnt == k) {
                break;
            }
        }
        return arr[0];
    }
};