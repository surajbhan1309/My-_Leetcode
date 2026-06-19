class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int n=s.size();
        unordered_map<char,int>f;
        int ans=0;
        for(int right=0;right<n;right++){
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