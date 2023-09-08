class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        int s;
        ret[0] = {1};
        for (int i = 1; i < numRows; ++i) {
            s = i + 1;
            ret[i] = vector<int>(s);
            ret[i][0] = ret[i][s - 1] = 1;
            for (int j = 1; j < s - 1; ++j) {
                ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
            }
        }
        return ret;
    }
};