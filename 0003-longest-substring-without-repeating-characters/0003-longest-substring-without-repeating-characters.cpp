class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int ans=0;
        unordered_map<char,int>f;
        for(int right=0;right<s.size();right++){
            f[s[right]]++;
            while(f[s[right]]>1){
                f[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;

        
    }
};