class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int, int> mp; 
        vector<int> ans;
        
        for(auto &x : nums) {
            if(mp[x] < k) {
                ans.push_back(x);
                mp[x]++; 
            }
        }
        return ans;
    }
};
