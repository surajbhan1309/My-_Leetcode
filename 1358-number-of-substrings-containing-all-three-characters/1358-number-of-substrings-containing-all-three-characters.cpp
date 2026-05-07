class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int>f(3,0);
        int left=0;
        int count=0;
        for(int right=0;right<n;right++){
            f[s[right]-'a']++;
            while(f[0]>0 && f[1]>0 && f[2]>0){
                count+=n-right;
                f[s[left]-'a']--;
                left++;
            }
        }
        return count;
        
    }
};