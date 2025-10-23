class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int>uno(nums.begin(),nums.end());
        vector<int>ans(uno.begin(),uno.end());
        sort(ans.begin(),ans.end(),greater<>());
        if(ans.size()<3){
            return ans[0];
        }
        else{
            return ans[2];
        }
        
    }
};