class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<pair<int, int>> q;
        int time = 0, fresh = 0;
        
        // Count fresh oranges and push rotten ones into queue
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    fresh++;
                }
                else if (grid[r][c] == 2) {
                    q.push({r, c});
                }
            }
        }
        
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!q.empty() && fresh > 0) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                auto [r, c] = q.front();
                q.pop();
                
                for (auto [dr, dc] : directions) {
                    int row = r + dr;
                    int col = c + dc;
                    
                    // Check bounds and fresh orange
                    if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != 1) {
                        continue;
                    }
                    
                    grid[row][col] = 2;  // make it rotten
                    q.push({row, col});
                    fresh--;
                }
            }
            time++;
        }
        
        return fresh == 0 ? time : -1;
        
    }
};