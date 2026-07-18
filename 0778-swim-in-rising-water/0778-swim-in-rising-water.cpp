class Solution {
public:
    int n;

    bool dfs(int mid, int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        if(x < 0 || y < 0 || x >= n || y >= n) return false;
        if(vis[x][y] || grid[x][y] > mid) return false;

        if(x == n-1 && y == n-1) return true;

        vis[x][y] = 1;

        return dfs(mid, x+1, y, grid, vis) ||
               dfs(mid, x-1, y, grid, vis) ||
               dfs(mid, x, y+1, grid, vis) ||
               dfs(mid, x, y-1, grid, vis);
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int l = 0, r = n*n;

        while(l < r) {
            int mid = l + (r - l)/2;
            vector<vector<int>> vis(n, vector<int>(n, 0));

            if(dfs(mid, 0, 0, grid, vis))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};