class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        while(slow!=fast);

        fast=0;
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;

    }
};
// Approach
// Treat the array as a linked list where each element points to the next index.
// Initialize two pointers, slow and fast, at the starting position.
// Move:
// slow one step at a time.
// fast two steps at a time.
// Since a cycle exists, the two pointers will eventually meet inside the cycle.
// Reset one pointer (fast) to the start.
// Move both pointers one step at a time.
// The point where they meet again is the entrance of the cycle, which corresponds to the duplicate number.
// Return that value.