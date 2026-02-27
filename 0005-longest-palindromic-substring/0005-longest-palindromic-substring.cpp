class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxlen=INT_MIN;
        int startpoint=-1;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispal(s,i,j)){
                    if(j-i+1>maxlen){
                        maxlen=j-i+1;
                        startpoint=i;
                    }
                }
            }
        }
        return s.substr(startpoint,maxlen);
        
    }
    bool ispal(string &s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};