class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>path;
        solve(ans,path,k,1,n);
        return ans;
    }
    void solve(vector<vector<int>>&ans,vector<int>&path,int k,int i,int n){
        if(path.size()==k){
            ans.push_back(path);
            return ;
        }
        if (i > n || path.size() + (n - i + 1) < k) {//not enough size to reach k
            return;
        }
        path.push_back(i);
        solve(ans,path,k,i+1,n);
        path.pop_back();
        solve(ans,path,k,i+1,n);
    }
};