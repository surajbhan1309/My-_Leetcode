class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int total=1<<n;
        vector<vector<int>>ans;
        for(int mask=0;mask<total;mask++){
            vector<int>subset;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
        
    }
};
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n=nums.size();
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
//         solve(nums,ans,path,i+1);
//     }
// };