class Solution {
public:
    int trailingZeroes(int n) {
        int p=5;
        int sum=0;
        while(true){
            if((n/p)==0) break;
            sum+=(n/p);
            p*=5;
        }
        return sum;
    }
};