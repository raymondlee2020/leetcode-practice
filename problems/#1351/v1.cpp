class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i = 0, j;
        while (i < m) {
            j = binarySearch(grid[i], 0, n);
            if (j < n) {
                break;
            }
            ++i;
        }
        if (i == m) {
            return 0;
        }
        int ret = 0;
        while (i < m) {
            while (j >= 0 && grid[i][j] < 0) {
                --j;
            }
            ++j;
            ret += (n - j);
            ++i;
        }
        return ret;
    }

    int binarySearch(vector<int> arr, int l, int r) {
        int mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (arr[mid] >= 0) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};