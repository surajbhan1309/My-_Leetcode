class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans=0;
        for(auto x:nums) {
            auto y=x;
            while(y) {
                if(y%10==digit) ans++;
                y/=10;
            }
        }
        return ans;
    }
};