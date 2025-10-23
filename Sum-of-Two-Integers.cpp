class Solution {
public:
    int getSum(int a, int b) {
         while (b != 0) {
            int tmp = (a & b) << 1;
            a = a ^ b;
            b = tmp;
        }
        return a;
    //     int carry; 
    //     while(b !=0 ) {
    //         carry = (a&b);
    //         a = a ^ b;//XOR add up two numbers easily without carry but if there was a carry
    //                     // then we have to add it
    //         b = (carry)<<1;
    //   }
    //   return a;
        
    }
};