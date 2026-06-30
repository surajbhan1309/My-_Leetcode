class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>path;
        sort(candidates.begin(),candidates.end());
        backtrack(ans,target,candidates,path,0);
        return ans;
    }
    // void backtrack(vector<vector<int>>&ans,int target,vector<int>&candidates,vector<int>&path,int start){
    //     if(target==0){
    //         ans.push_back(path);
    //         return ;
    //     }
    //     for(int i=start;i<candidates.size();i++){
    //         if(candidates[i]>target) continue;
    //         path.push_back(candidates[i]);
    //         backtrack(ans,target-candidates[i],candidates,path,i);
    //         path.pop_back();
    //     }
    // }
    void backtrack(vector<vector<int>>&ans,int target,vector<int>&candidates,vector<int>&path,int i){
        if(target==0){
            ans.push_back(path);
            return ;
        }
        if(i==candidates.size()){
            return;
        }
        if(candidates[i]<=target){
            path.push_back(candidates[i]);
            backtrack(ans,target-candidates[i],candidates,path,i);
            path.pop_back();
        }
        backtrack(ans,target,candidates,path,i+1);

    }
};