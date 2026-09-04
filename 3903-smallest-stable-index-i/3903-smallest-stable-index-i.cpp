class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            int maxi=*max_element(nums.begin(),nums.begin()+i+1);
            int mini=*min_element(nums.begin()+i,nums.end());
            int diff=abs(maxi-mini);
            if(diff<=k){
                ans=i;
                return ans;
            }
        }
        return ans;
        
    }
};