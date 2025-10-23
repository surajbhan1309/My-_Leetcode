class Solution {
public:

    void subset(vector<int>&nums,int i,vector<vector<int>>&result,vector<int>&path){
        if(i==nums.size()){
            result.push_back(path);
            return;
        }
        path.push_back(nums[i]);
        subset(nums,i+1,result,path);

        path.pop_back();
        int index=i+1;
        while(index<nums.size() && nums[index]==nums[index-1]){
            index++;
        }
        subset(nums,index,result,path);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>path;
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        subset(nums,0,result,path);
        return result;
        
    }
};