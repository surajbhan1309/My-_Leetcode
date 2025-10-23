class Solution {
public:
    void backtrack(vector<int>& candidates,int target,vector<vector<int>>&result,vector<int>&path,int start){
        if(target==0){
            result.push_back(path);
            
        }
        for(int i=start;i<candidates.size();i++){
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            if(candidates[i]>target){
                break;
            }
            path.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],result,path,i+1);
            path.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<vector<int>>result;
      vector<int>path;
      sort(candidates.begin(),candidates.end());
      backtrack(candidates,target,result,path,0);
      return result; 
    }
};