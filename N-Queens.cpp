class Solution {
public:
    // Add current board configuration to the solution in string format
    void addSolution(vector<vector<int>> &board, vector<vector<string>> &solution, int n) {
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string row = "";
            for (int j = 0; j < n; j++) {
                row += board[i][j] == 1 ? 'Q' : '.';
            }
            temp.push_back(row);
        }
        solution.push_back(temp);
    }

    // Check if placing queen at (row, col) is safe
    bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
        // Check left side of the current row
        for (int j = col - 1; j >= 0; j--) {
            if (board[row][j] == 1) return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) return false;
        }

        // Check lower-left diagonal
        for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 1) return false;
        }

        return true;
    }

    // Backtracking function to place queens
    void solve(int col, vector<vector<string>> &solution, vector<vector<int>> &board, int n) {
        if (col == n) {
            addSolution(board, solution, n);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 1; // Place queen
                solve(col + 1, solution, board, n);
                board[row][col] = 0; // Backtrack
            }
        }
    }

    // Main function to solve N-Queens
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solution;
        vector<vector<int>> board(n, vector<int>(n, 0));
        solve(0, solution, board, n);
        return solution;
    }
};
