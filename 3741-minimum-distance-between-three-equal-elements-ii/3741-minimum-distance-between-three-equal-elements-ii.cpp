class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>Vmap;
        for(int i=0;i<nums.size();i++){
            Vmap[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto &x:Vmap){
            auto &pos=x.second;
            if(pos.size()<3) continue;
            for(int i=0;i+2<pos.size();i++){
                ans=min(ans,2*abs(pos[i]-pos[i+2]));
            }
            
            
        }
        return (ans==INT_MAX)?-1:ans;
        
    }
};