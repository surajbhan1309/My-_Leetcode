class Solution {
public:
    void solve(vector<string>&ans,int n,string s){
        int size=s.size();
        if(size==n){
            ans.push_back(s);
            return;
        }
        solve(ans,n,s+'1');
        if(s.empty() || s.back()!='0'){
            solve(ans,n,s+'0');
        }

    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        string s="";
        solve(ans,n,s);
        return ans;
    }
};