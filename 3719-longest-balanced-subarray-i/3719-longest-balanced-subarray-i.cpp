class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
                set<int>evens;
                set<int>odds;
            for(int j=i;j<n;j++){
                int x=nums[j];
                if(x&1) odds.insert(x);
                else evens.insert(x);
                if(evens.size()==odds.size()){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
        
    }
};