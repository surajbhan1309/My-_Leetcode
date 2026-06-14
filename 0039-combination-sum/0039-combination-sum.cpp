class Solution {
public:
    void backtrack(vector<vector<int>>&ans,vector<int>&path,vector<int>&candidates,int target,int start)
    {
        if (target==0){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(candidates[i]>target){
                break;
            }
            path.push_back(candidates[i]);
            backtrack(ans,path,candidates,target-candidates[i],i);
            path.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>path;
        sort(candidates.begin(),candidates.end());
        backtrack(ans,path,candidates,target,0);
        return ans;
        
    }
};