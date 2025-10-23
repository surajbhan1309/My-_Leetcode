class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int col = y; col <= y + k - 1; col++) {
            int start = x;
            int end = x + k - 1;
            while (start < end) {
                swap(grid[start][col], grid[end][col]);
                start++;
                end--;
            }
        }
        return grid;
    }
};
