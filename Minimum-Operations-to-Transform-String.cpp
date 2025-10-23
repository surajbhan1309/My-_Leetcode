class Solution {
public:
    int minOperations(string s) {
        int mini=0;
        for(char &x:s){
            int count=(26-(x-'a'))%26;
            mini=max(mini,count);
        }
        return mini;
        
    }
};