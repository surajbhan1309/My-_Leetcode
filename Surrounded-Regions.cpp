class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();        // rows
        int n = board[0].size();     // cols
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // First and Last row
        for(int j = 0; j < n; j++) {
            if(!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, vis, board, m, n, delrow, delcol);
            }
            if(!vis[m-1][j] && board[m-1][j] == 'O') {
                dfs(m-1, j, vis, board, m, n, delrow, delcol);
            }
        }

        // First and Last column
        for(int i = 0; i < m; i++) {
            if(!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, vis, board, m, n, delrow, delcol);
            }
            if(!vis[i][n-1] && board[i][n-1] == 'O') {
                dfs(i, n-1, vis, board, m, n, delrow, delcol);
            }
        }

        // Flip unvisited 'O' to 'X'
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board,
             int m, int n, int delrow[], int delcol[]) {
        vis[row][col] = 1;

        for(int k = 0; k < 4; k++) {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
               !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, board, m, n, delrow, delcol);
            }
        }
    }
};
