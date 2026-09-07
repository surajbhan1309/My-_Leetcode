class Solution {
public:
    int distinctSubseqII(string s) {
        long long mod=1e9+7;
        vector<long long>last(26,0);
        long long total=0;
        for(char c:s){
            int idx=c-'a';
            long long new_count=(total+1-last[idx]+mod)%mod;
            total=(total+new_count)%mod;
            last[idx]=(last[idx]+new_count)%mod;
        }
        return (int)total;
    }
};