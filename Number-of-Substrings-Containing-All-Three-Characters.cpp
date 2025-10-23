class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0;
        vector<int>charfreq(3,0);
        int count=0;
        for(int right=0;right<s.size();right++){
            charfreq[s[right]-'a']++;
            while(charfreq[0]&&charfreq[1]&&charfreq[2]){
                count+=s.size()-right;
                charfreq[s[left]-'a']--;
                left++;
            }
            
        }
        return count;
        
    }
};