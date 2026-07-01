class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();

        vector<int>lps(m,0);
        LPS(needle,lps);

        int i=0;
        int j=0;

        while(i<n){
            if(needle[j]==haystack[i]){
                i++;
                j++;
            }
            if(j==m){
                return (i-j);
                break;
            }
            else if(i<n && needle[j]!=haystack[i]){
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
    return -1;
    }
    void LPS(string pattern ,vector<int>&lps){
        int m=pattern.size();
        int len=0;

        lps[0]=0;
        int i=1;
        while(i<m){
            if(pattern[i]==pattern[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len>0){
                    len=lps[len-1];//you can also write len=len-1;
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
};