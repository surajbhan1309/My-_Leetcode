class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // Stores {number, index}
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // The number we need
            if (mp.find(complement) != mp.end()) { // If found in map
                return {mp[complement], i}; // Return the correct indices
            }
            mp[nums[i]] = i; // Store the current number's index
        }
        
        return {}; // No solution found
    }
};
