class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            
            vector<int> indices;
            for (int j = i; j < n; j++) {
                if (nums[j] == nums[i]) {
                    indices.push_back(j);
                    visited[j] = true;
                }
            }
            
            if (indices.size() == 3) {
                if (indices[1] - indices[0] == indices[2] - indices[1]) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
