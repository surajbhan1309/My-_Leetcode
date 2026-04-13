class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        string ans="";
        for(auto &x:nums){
            string c=to_string(x);
            ans+=c;
        }
        int count=0;
        char t=digit+'0';
        for(auto &c:ans){
            if(c==t) count++;
        }
        return count;
        
    }
};