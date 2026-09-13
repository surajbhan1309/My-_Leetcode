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
            
            if (indices.size() == 3) {
                if (indices[1] - indices[0] == indices[2] - indices[1]) {
                    ans++;
                }
            }
        } 
        
        return ans;
    } 
};
