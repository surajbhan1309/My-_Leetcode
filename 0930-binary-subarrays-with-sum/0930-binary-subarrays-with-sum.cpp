class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>prefix;
        prefix[0]=1;
        int sum=0,ans=0;
        for(int &num:nums){
            sum+=num;
            ans+=prefix[sum-goal];
            prefix[sum]++;
        }
        return ans;
        
    }
};