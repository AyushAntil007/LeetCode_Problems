class Solution {
public:
    bool dfs(int x, int y, int m, int n, vector<vector<int>>& vis, vector<vector<char>>& board, string &word, int k) {
        if (k == word.size()) return true;
        vis[x][y] = 1;

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && board[nx][ny] == word[k]) {
                if (dfs(nx, ny, m, n, vis, board, word, k + 1))
                    return true;
            }
        }

        vis[x][y] = 0; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, m, n, vis, board, word, 1))
                        return true;
                }
            }
        }
        return false;
    }
};
