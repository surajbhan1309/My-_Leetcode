class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        solve(s,ans,path,0);
        return ans;
    }
    void solve(string &s,vector<vector<string>>&ans,vector<string>&path,int start){
        if(start==s.size()){
            ans.push_back(path);
            return ;
        }
        for(int i=start;i<s.size();i++){
            if(isPal(s,start,i)){
                path.push_back(s.substr(start,i-start+1));
                solve(s,ans,path,i+1);
                path.pop_back();
            }
        }
    }
    bool isPal(string &s,int left,int right){
        while(left<right){
            if(s[left++]!=s[right--]){
                return false;
            }
        }
        return true;
    }
};