class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans="";
        int n=s.size();
        int start=0;
        while(start<n){
            if(start<n && s[start]==' ') start++;
            int end=start;
            while(end<n && s[end]!=' ') end++;
            if(start<end){
                //if there are multiple spaces then start==end and ans will have extra spaces
                //so condition of start<end
                string word=s.substr(start,end-start);
                reverse(word.begin(),word.end());
                if(!ans.empty()) ans+=" ";
                ans+=word;
            }
            start=end;
        }
        return ans;
        
    }
};