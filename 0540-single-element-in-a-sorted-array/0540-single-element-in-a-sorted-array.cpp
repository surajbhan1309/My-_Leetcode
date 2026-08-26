class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            // mid ^ 1 finds the expected twin index:
            // If mid is even, mid ^ 1 is mid + 1
            // If mid is odd, mid ^ 1 is mid - 1
            if(nums[mid]==nums[mid^1]){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return nums[low];
    }
};
