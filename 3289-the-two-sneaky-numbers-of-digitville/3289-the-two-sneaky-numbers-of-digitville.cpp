class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>Vmap;
        for(auto &num:nums){
            Vmap[num]++;
        }
        vector<int>ans;
        for(auto &x:Vmap){
            if(x.second>1) ans.push_back(x.first);
        }
        return ans;
        
    }
};