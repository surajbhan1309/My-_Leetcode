class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[nums[0]];
        
        // Phase 1: Finding the intersection point inside the cycle
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        
        // Phase 2: Finding the entrance to the cycle (the duplicate number)
        fast=0;
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
