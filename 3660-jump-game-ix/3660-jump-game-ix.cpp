class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixmax(n),suffixmax(n),ans(n);
        prefixmax[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixmax[i]=max(prefixmax[i-1],nums[i]);
        }
        suffixmax[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffixmax[i]=min(suffixmax[i+1],nums[i]);
        }
        ans[n-1]=prefixmax[n-1];
        for(int i=n-2;i>=0;i--){
            if(prefixmax[i]>suffixmax[i+1]) ans[i]=ans[i+1];
            else ans[i]=prefixmax[i];
        }
        return ans;
        
    }
};