class Solution {
public:
    void sortColors(vector<int>& nums) {
    int left=0,right=nums.size()-1,s=0;
    while(s<=right){
        if(nums[s]==0){
            swap(nums[left++],nums[s++]);
        }
        else if(nums[s]==1){
            s++;
        }
        else{
            swap(nums[s],nums[right--]);
        }
    }
        
    }
};