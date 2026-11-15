class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        vector<long long>pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
        }
        long long min_sum=-1;
        for(int len=l;len<=r;len++){
            for(int i=0;i<=n-len;i++){
                long long current_sum=pref[i+len]-pref[i];
                if(current_sum>0){
                    if(min_sum==-1 || current_sum<min_sum){
                        min_sum=current_sum;
                    }
                }
            }
        }
        return (int)min_sum;
    }
};