class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(auto &x:nums){
            if(x==0) count++;
        }
        int ans=count;
        int c=0;
        for(int i=n-1;i>=0 && count>0;i--){
            if(nums[i]==0) c++;
            count--;
        }
        return ans-c;


    }
};