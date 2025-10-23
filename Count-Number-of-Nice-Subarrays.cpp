class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>prefix;
        prefix[0]=1;
        int ans=0;
        int sum=0;
        for(int num:nums){
            sum+=num%2;
            ans+=prefix[sum-k];
            prefix[sum]++;
        }
        return ans;

        
    }
};