class Solution {
public:
    int m, n, l;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        l = word.size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtrack(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board, int i, int j, string word, int idx) {
        if (i < 0 || i == m || j < 0 || j == n || board[i][j] != word[idx]) {
            return false;
        }
        if (idx == l - 1) {
            return true;
        }
        board[i][j] = '0';
        if (backtrack(board, i + 1, j, word, idx + 1)) return true;
        if (backtrack(board, i, j + 1, word, idx + 1)) return true;
        if (backtrack(board, i - 1, j, word, idx + 1)) return true;
        if (backtrack(board, i, j - 1, word, idx + 1)) return true;
        board[i][j] = word[idx];
        return false;
    }
};