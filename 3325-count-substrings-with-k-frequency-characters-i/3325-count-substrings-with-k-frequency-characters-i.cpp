class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int left=0;
        int ans=0;
        unordered_map<char,int>map;
        for(char c:s){
            map[c]++;
            while(map[c]==k){
                map[s[left]]--;
                left++;
            }
            ans+=left;
        }
        return ans;
        
        
    }
};