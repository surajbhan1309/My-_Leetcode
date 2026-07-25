class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Step 1: Compute prefix sums for each row
        for (int r = 0; r < rows; ++r) {
            for (int c = 1; c < cols; ++c) {
                matrix[r][c] += matrix[r][c - 1];
            }
        }
        
        int count = 0;
        
        // Step 2: Iterate over all pairs of columns (c1, c2)
        for (int c1 = 0; c1 < cols; ++c1) {
            for (int c2 = c1; c2 < cols; ++c2) {
                unordered_map<int, int> sum_map;
                sum_map[0] = 1; 
                
                int current_sum = 0;
                
                // Step 3: Iterate through rows to find matching submatrices
                for (int r = 0; r < rows; ++r) {
                    int row_sum = matrix[r][c2] - (c1 > 0 ? matrix[r][c1 - 1] : 0);
                    current_sum += row_sum;
                    
                    if (sum_map.find(current_sum - target) != sum_map.end()) {
                        count += sum_map[current_sum - target];
                    }
                    
                    sum_map[current_sum]++;
                }
            }
        }
        
        return count;
    }
};
