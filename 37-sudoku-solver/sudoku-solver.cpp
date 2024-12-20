class Solution {
public:
    bool isValid(char num, int row, int col, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num) // check row
                return false;
            if (board[row][i] == num) // check col
                return false;

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] ==
                num) // check 3x3 sub matrix
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board.size(); c++) {
                if (board[r][c] == '.') { // cell is empty
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(num, r, c, board)) {
                            board[r][c] = num; // Try placing the number

                            // Recursively attempt to solve the rest of the
                            // board
                            if (solve(board))
                                return true; // If solved, return true

                            board[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { bool check = solve(board); }
};