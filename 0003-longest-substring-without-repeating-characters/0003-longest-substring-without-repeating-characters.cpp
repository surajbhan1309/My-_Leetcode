class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int max_len=0;
        int left=0;
        map<int,int>mp;
        for(int right=0;right<n;right++){
            mp[s[right]]++;
            while(mp[s[right]]>1){
                mp[s[left]]--;
                left++;
            }
            max_len=max(max_len,right-left+1);
        }
        return max_len;
    }
};