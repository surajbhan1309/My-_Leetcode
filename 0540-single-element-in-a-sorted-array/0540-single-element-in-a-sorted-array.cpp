// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int n=nums.size();
//         int low=0;
//         int high=n-1;
//         while(low<high){
//             int mid=low+(high-low)/2;
//             if(nums[mid]==nums[mid^1]){
//                 low=mid+1;
//             }
//             else{
//                 high=mid;
//             }
//         }
//         return nums[low];
//     }
// };
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;

        while(start<end){
            int mid=start+(end-start)/2;
            
            if (mid % 2 == 1) mid--;

            if(nums[mid]==nums[mid+1]){
                start=mid+2;
            }
            else{
                end=mid;
            }
            
        } 
        return nums[start];
          
    }
};