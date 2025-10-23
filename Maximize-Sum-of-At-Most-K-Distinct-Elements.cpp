class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        vector<int>ans;
        for(int &x:nums){
            if(find(ans.begin(),ans.end(),x)==ans.end())ans.push_back(x);
            if(ans.size()==k) break;
        }
        return ans;
        
    }
};