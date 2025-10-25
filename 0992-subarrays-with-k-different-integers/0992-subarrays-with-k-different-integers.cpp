class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
    int atmost(vector<int>&nums,int k){
        int left=0,ans=0;
        unordered_map<int,int>count;
        for(int right=0;right<nums.size();right++){
            if(count[nums[right]]==0) k--;
            count[nums[right]]++;
            while(k<0){
                if(count[nums[left]]==1) k++;
                count[nums[left]]--;
                left++;
            }
            ans+=right-left+1;
        }
        return ans;
    }
};