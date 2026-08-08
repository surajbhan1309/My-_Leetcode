class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int max_len=0;
        int left=0;
        vector<int>mp(26,0);
        for(int right=0;right<n;right++){
            mp[s[right]-'a']++;
            while(mp[s[right]-'a']>1){
                mp[s[left]-'a']--;
                left++;
            }
            max_len=max(max_len,right-left+1);
        }
        return max_len;
    }
};