class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ret, mid, n = arr.size(), l = 0, r = n - 1;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                ret = mid;
                break;
            } else if (arr[mid] < arr[mid - 1]) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return ret;
    }
};