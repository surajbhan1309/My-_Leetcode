class Solution {
public:
    int SumofPrimes(int L, int R) {
        vector<bool>prime(R+1,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i*i<=R;i++){
            if(prime[i]){
                for(int j=i*i;j<=R;j+=i){
                    prime[j]=false;
                }
            }
        }

        int sum= 0;
        for (int i = L; i <= R; i++)
            if (prime[i]) sum+=i;
        return sum;
}
    int sumOfPrimesInRange(int n) {
        string revstr=to_string(n);
        reverse(revstr.begin(),revstr.end());
        int digit=stoi(revstr);
        if(digit<n) swap(digit,n);
        return SumofPrimes(n,digit);
    }
};