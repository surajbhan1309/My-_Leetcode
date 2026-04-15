class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prefix;
        int sum=0,count=0;
        prefix[0]=1;
        for(auto &num:nums){
            sum+=num;
            count+=prefix[sum-k];
            prefix[sum]++;
        }
        return count;
    }
};