class Solution {
public:
    int numSub(string s) {
        int count=0;
        int total=0;
        int mod=1e9+7;
        for(char a:s){
            if(a=='1'){
                count++;
            }
            else{
                count=0;
            }
        total=(total+count)%mod;
        }
    return total;
    }
};