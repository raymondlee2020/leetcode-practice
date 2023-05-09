class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int ys = 0, ye = matrix.size() - 1, xs = 0, xe = matrix[0].size() - 1;
        while (xs < xe && ys < ye) {
            for (int x = xs; x < xe; ++x) {
                ret.push_back(matrix[ys][x]);
            }
            for (int y = ys; y < ye; ++y) {
                ret.push_back(matrix[y][xe]);
            }
            for (int x = xe; x > xs; --x) {
                ret.push_back(matrix[ye][x]);
            }
            for (int y = ye; y > ys; --y) {
                ret.push_back(matrix[y][xs]);
            }
            ++xs, --xe, ++ys, --ye;
        }
        if (xs == xe) {
            for (int y = ys; y <= ye; ++y) {
                ret.push_back(matrix[y][xs]);
            }
        } else if (ys == ye) {
            for (int x = xs; x <= xe; ++x) {
                ret.push_back(matrix[ys][x]);
            }
        }
        return ret;
    }
};