class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>Vmap;
        int left=0;
        int n=s.size();
        int ans=0;
        for(int right=0;right<n;right++){
            Vmap[s[right]]++;
            while(Vmap[s[right]]>1){
                Vmap[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
        
    }
};