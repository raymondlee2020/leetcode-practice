class Solution {
public:
    int m, n;

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size();
        n = matrix[0].size();
        int l = 0, r = m * n, mid;
        pair<int, int> idxp;
        while (l < r) {
            mid = l + (r - l) / 2;
            idxp = getIndexPair(mid);
            if (matrix[idxp.first][idxp.second] > target) {
                r = mid;
            } else if (matrix[idxp.first][idxp.second] < target) {
                l = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }

    pair<int, int> getIndexPair(int idx) {
        return {idx / n, idx % n};
    }
};