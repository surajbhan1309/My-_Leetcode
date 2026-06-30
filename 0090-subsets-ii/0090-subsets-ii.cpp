class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> path;
        solve(nums, ans, path, 0);
        return ans;
    }

    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& path, int start) {
        ans.push_back(path);

        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;

            path.push_back(nums[i]);
            solve(nums, ans, path, i + 1);
            path.pop_back();
        }
    }
};
// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         vector<vector<int>>ans;
//         vector<int>path;
//         solve(nums,ans,path,0);
//         return ans;
//     }
//     void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&path,int i){
//         if(i==nums.size()){
//             ans.push_back(path);
//             return;
//         }
//         path.push_back(nums[i]);
//         solve(nums,ans,path,i+1);
//         path.pop_back();
//         while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
//             i++;
//         }
//         solve(nums,ans,path,i+1);
//     }
// };
// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         set<vector<int>>st;
//         int n=nums.size();
//         sort(nums.begin(),nums.end());

//         for(int mask=0;mask<(1<<n);mask++){
//             vector<int>subset;
//             for(int i=0;i<n;i++){
//                 if(mask&(1<<i)){
//                     subset.push_back(nums[i]);
//                 }
//             }
//             st.insert(subset);
//         }
//         vector<vector<int>>ans(st.begin(),st.end());
//         return ans;

        
//     }
// };

