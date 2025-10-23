class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        int num1=num;
        if(num >= 0 && num <= 9)
        {
            return num;
        }
        while(num>0){
            sum=sum+num%10;
            num=num/10;
            
        }
        return addDigits(sum);
        
        
    }
};