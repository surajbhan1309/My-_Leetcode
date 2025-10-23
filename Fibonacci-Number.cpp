class Solution {
public:
    int fib(int n) {
    int prev1=0;
    int prev2=1;
    int curr=0;

    if(n==0)return prev1;

    for(int i=2;i<=n;i++){
        curr=prev1+prev2;
        prev1=prev2;
        prev2=curr;
        curr++;

    }
    return prev2;
    }
};