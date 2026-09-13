class Solution { 
public: 
    int countSpecialIntegers(vector<int>& nums) { 
        map<int, vector<int>> mp; 
        int ans = 0; 
        int n = nums.size(); 
        
        for(int i = 0; i < n; i++){ 
            mp[nums[i]].push_back(i); 
        } 
        
        for(auto &x : mp){ 
            vector<int>& indices = x.second;
            
            if (indices.size() < 3) {
                continue;
            }
            
            int diff = indices[1] - indices[0];
            bool is_special = true;
            
            for (int i = 2; i < indices.size(); i++) {
                if (indices[i] - indices[i-1] != diff) {
                    is_special = false;
                    break;
                }
            }
            
            if (is_special) {
                ans++;
            }
        } 
        
        return ans;
    } 
};
