class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        deque<pair<int, int>> dq;
        for (int i = n - 1; i > 0; --i) {
            dq.push_back({0, matrix[i][0]});
            for (int j = 0; j < n; ++j) {
                while (dq.front().first < j - 1) {
                    dq.pop_front();
                }
                if (j < n - 1) {
                    while (!dq.empty() && dq.back().second > matrix[i][j + 1]) {
                        dq.pop_back();
                    }
                    dq.push_back({j + 1, matrix[i][j + 1]});
                }
                matrix[i - 1][j] += dq.front().second;
            }
            dq.clear();
        }
        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};