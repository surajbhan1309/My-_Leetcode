class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd=0;
        int countO=0;
        int sumEven=0;
        int countE=0;
        for(int i=1;i<INT_MAX;i+=2){
            sumOdd+=i;
            countO++;
            if(countO==n)break;
        }
        for(int i=2;i<INT_MAX;i+=2){
            sumEven+=i;
            countE++;
            if(countE==n)break;
        }
        while(sumEven!=0){
            int var=sumEven;
            sumEven=sumOdd%sumEven;
            sumOdd=var;
        }
        return sumOdd;
        
    }
};