class Solution {
public:
    vector<vector<bool>> rowused;
    vector<vector<bool>> colused;
    vector<vector<vector<bool>>> gridused;

    void solveSudoku(vector<vector<char>>& board) {
        init(board);
        bool done = false;
        pair<int, int> slot = board[0][0] == '.' ? pair<int, int>(0, 0) : next(board, 0, 0);
        backtrack(board, done, slot.first, slot.second);
    }

    void init(vector<vector<char>>& board) {
        rowused = vector<vector<bool>>(9, vector<bool>(10, false));
        colused = vector<vector<bool>>(9, vector<bool>(10, false));
        gridused = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(10, false)));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                int num = board[i][j] - '0';
                rowused[i][num] = true;
                colused[j][num] = true;
                gridused[i / 3][j / 3][num] = true;
            }
        }
    }

    bool isvalid(int i, int j, int d) {
        return !(rowused[i][d] || colused[j][d] || gridused[i / 3][j / 3][d]);
    }

    void use(vector<vector<char>>& board, int i, int j, int num) {
        board[i][j] = char(num + '0');
        rowused[i][num] = true;
        colused[j][num] = true;
        gridused[i / 3][j / 3][num] = true;
    }

    void rollback(vector<vector<char>>& board, int i, int j, int num) {
        board[i][j] = '.';
        rowused[i][num] = false;
        colused[j][num] = false;
        gridused[i / 3][j / 3][num] = false;
    }

    pair<int, int> next(vector<vector<char>>& board, int i, int j) {
        if (i == 8 && j == 8) {
            return {-1, -1};
        } else if (i == 8) {
            i = 0;
            ++j;
        } else {
            ++i;
        }
        if (board[i][j] != '.') {
            return next(board, i, j);
        }
        return {i, j};
    }

    void backtrack(vector<vector<char>>& board, bool& done, int i, int j) {
        pair<int, int> slot = next(board, i, j);
        for (int num = 1; num < 10; ++num) {
            if (!isvalid(i, j, num)) {
                continue;
            }
            use(board, i, j, num);
            if (slot.first == -1 && slot.second == -1) {
                done = true;
                return;
            }
            backtrack(board, done, slot.first, slot.second);
            if (done) {
                return;
            }
            rollback(board, i, j, num);
        }
    }
};