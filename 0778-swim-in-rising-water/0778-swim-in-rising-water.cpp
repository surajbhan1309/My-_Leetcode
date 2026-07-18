class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        int dirX[] = {-1, 1, 0, 0};
        int dirY[] = {0, 0, -1, 1};
        
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            
            int max_elevation = curr[0];
            int r = curr[1];
            int c = curr[2];
            
            if (r == n - 1 && c == n - 1) {
                return max_elevation;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dirX[i];
                int nc = c + dirY[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.push({max(max_elevation, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     int n;

//     bool dfs(int mid, int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis) {
//         if(x < 0 || y < 0 || x >= n || y >= n) return false;
//         if(vis[x][y] || grid[x][y] > mid) return false;

//         if(x == n-1 && y == n-1) return true;

//         vis[x][y] = 1;

//         return dfs(mid, x+1, y, grid, vis) ||
//                dfs(mid, x-1, y, grid, vis) ||
//                dfs(mid, x, y+1, grid, vis) ||
//                dfs(mid, x, y-1, grid, vis);
//     }

//     int swimInWater(vector<vector<int>>& grid) {
//         n = grid.size();
//         int l = 0, r = n*n;

//         while(l < r) {
//             int mid = l + (r - l)/2;
//             vector<vector<int>> vis(n, vector<int>(n, 0));

//             if(dfs(mid, 0, 0, grid, vis))
//                 r = mid;
//             else
//                 l = mid + 1;
//         }

//         return l;
//     }
// };