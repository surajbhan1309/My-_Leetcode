class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>path;
        solve(nums,ans,path,0);
        return ans;
    }
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&path,int start){
        ans.push_back(path);
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            solve(nums,ans,path,i+1);
            path.pop_back();
        }
    }
};