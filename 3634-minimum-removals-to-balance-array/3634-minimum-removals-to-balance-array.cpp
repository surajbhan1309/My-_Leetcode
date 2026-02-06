class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] > (long) nums[i] * k) {
            i++;
            }
        }

        return i;
        
    }
};