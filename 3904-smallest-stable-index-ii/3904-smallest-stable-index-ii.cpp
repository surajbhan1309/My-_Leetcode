class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>maxi,mini;
        int n=nums.size();
        int mx=nums[0];
        maxi.push_back(mx);
        for(int i=1;i<n;i++){
            if(nums[i]>mx){
                mx=nums[i];
            }
            maxi.push_back(mx);
        }
        int mi=nums[n-1];
        mini.push_back(mi);
        for(int i=n-2;i>=0;i--){
            if(nums[i]<mi){
                mi=nums[i];
            }
            mini.push_back(mi);
        }
        reverse(mini.begin(),mini.end());
        for(int i=0;i<n;i++){
            if(abs(maxi[i]-mini[i])<=k) return i;
        }
        return -1;
        
        
        
    }
};