class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;;
        double halfPow=myPow(x,n/2);
        if(n%2==0){
            return halfPow*halfPow;
        }
        if(n>0){
            return x*halfPow*halfPow;
        }
        else{
            return (1/x)*halfPow*halfPow;
        }
        return x;
    }
};