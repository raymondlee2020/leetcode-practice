class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));
        int ys = 0, ye = n - 1, xs = 0, xe = n - 1, num = 1;
        while (xs < xe && ys < ye) {
            for (int x = xs; x < xe; ++x) {
                ret[ys][x] = num++;
            }
            for (int y = ys; y < ye; ++y) {
                ret[y][xe] = num++;
            }
            for (int x = xe; x > xs; --x) {
                ret[ye][x] = num++;
            }
            for (int y = ye; y > ys; --y) {
                ret[y][xs] = num++;
            }
            ++xs, --xe, ++ys, --ye;
        }
        if (xs == xe) {
            for (int y = ys; y <= ye; ++y) {
                ret[y][xs] = num++;
            }
        } else if (ys == ye) {
            for (int x = xs; x <= xe; ++x) {
                ret[ys][x] = num++;
            }
        }
        return ret;
    }
};