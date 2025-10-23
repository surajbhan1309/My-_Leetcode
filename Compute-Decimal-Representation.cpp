class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>ans;
        int i=0;
        long long mul=1;
        while(n>0){
            int digit=n%10;
            n/=10;
            int res=digit*mul;
            if(digit!=0){
            ans.push_back(res);
            }
            i++;
            mul*=10;
            
        }
        sort(ans.rbegin(),ans.rend());
        return ans;
        
    }
};