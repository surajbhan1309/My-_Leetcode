class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int mid=start+(end-start)/2;

        while(start<end){
            
            if (mid % 2 == 1) mid--;

            if(nums[mid]==nums[mid+1]){
                start=mid+2;
            }
            else{
                end=mid;
            }
            mid=start+(end-start)/2;
            
        } 
        return nums[start];
          
    }
};