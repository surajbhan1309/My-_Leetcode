class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans="";
        int start=0;
        int n=s.size();
        while(start<n){
            while(start<n && s[start]==' ') start++;
            int end=start;
            while(end<n && s[end]!=' ')end++;
            if(start<end){
                string str=s.substr(start,end-start);
                reverse(str.begin(),str.end());
                if(!ans.empty()) ans+=" ";
                ans+=str;
            }
            start=end;
        }
        return ans;
    }
};