class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans="";
        int start=0;
        int n=s.size();
        while(start<n){
            if(start<n && s[start]==' ') start++;
            int end=start;
            while(end<n && s[end]!=' ') end++;
            if(start<end){
                string temp=s.substr(start,end-start);
                reverse(temp.begin(),temp.end());
                if(!ans.empty()) ans+=" ";
                ans+=temp;
            }
            start=end;
        }
        return ans;
        
    }
};