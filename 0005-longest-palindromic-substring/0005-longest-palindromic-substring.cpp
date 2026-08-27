class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int len=0;
        int start=-1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispal(i,j,s)){
                    if(j-i+1>len){
                        len=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,len);
    }
    bool ispal(int i,int j,string &s){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;

    }
};