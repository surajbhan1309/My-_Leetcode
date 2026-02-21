class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Min-heap: {max_height_so_far, r, c}
        priority_queue<
            array<int,3>,
            vector<array<int,3>>,
            greater<>
        > pq;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        const int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        
        pq.push({grid[0][0], 0, 0});
        
        while (!pq.empty()) {
            auto [maxH, r, c] = pq.top();
            pq.pop();
            
            if (visited[r][c]) continue;
            visited[r][c] = true;
            
            // If reached target, first time = optimal
            if (r == n - 1 && c == n - 1) return maxH;
            
            for (auto &d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    pq.push({max(maxH, grid[nr][nc]), nr, nc});
                }
            }
        }
        
        return -1; // Should never reach here
    }
};