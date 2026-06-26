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
        int j=n-1;
        while(count--){
            if(nums[j]==0) c++;
            j--;
        }
        return ans-c;


    }
};