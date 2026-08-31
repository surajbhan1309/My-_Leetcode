class Solution {
public:
    int countValidPrefixes(string s) {
        int one=0;
        int zero=0;
        int ans=0;
        for(auto &c:s){
            if(c=='0') zero++;
            if(c=='1') one++;
            if(abs(zero-one)<=1) ans++;
        }
        return ans;
    }
};