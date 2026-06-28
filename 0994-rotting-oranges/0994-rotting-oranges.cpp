class Solution { 
public: 
    int orangesRotting(vector<vector<int>>& grid) { 
        int rows = grid.size(); 
        int cols = grid[0].size(); 
        queue<pair<int, int>> q; 
        int time = 0, fresh = 0; 
        
        for (int r = 0; r < rows; r++) { 
            for (int c = 0; c < cols; c++) { 
                if (grid[r][c] == 1) { 
                    fresh++; 
                } else if (grid[r][c] == 2) { 
                    q.push({r, c}); 
                } 
            } 
        } 
        
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};
        
        while (!q.empty() && fresh > 0) { 
            int qSize = q.size(); 
            for (int i = 0; i < qSize; i++) { 
                auto [r, c] = q.front(); 
                q.pop(); 
                
                for (int d = 0; d < 4; d++) { 
                    int row = r + dRow[d]; 
                    int col = c + dCol[d]; 
                    
                    if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != 1) { 
                        continue; 
                    } 
                    grid[row][col] = 2; 
                    q.push({row, col}); 
                    fresh--; 
                } 
            } 
            time++; 
        } 
        
        return fresh == 0 ? time : -1; 
    } 
};
