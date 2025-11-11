class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>path;
        recur(s,0,path,result);
        return result;
    }
    void recur(string &s,int start,vector<string>&path,vector<vector<string>>&result){
        if(start==s.length()){
            result.push_back(path);
            return;
        }
        for(int end=start+1;end<=s.length();end++){
            if(isPalindrome(s,start,end-1)){
                path.push_back(s.substr(start,end-start));
                recur(s,end,path,result);
                path.pop_back();
            }
        }

    }
    bool isPalindrome(string &s,int left,int right){
        while(left<right){
            if(s[left++]!=s[right--]){
                return false;
            }
        }
        return true;
    }
};