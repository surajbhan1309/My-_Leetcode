class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(n>m) return false;
        vector<int>f1(26,0);
        vector<int>f2(26,0);
        for(char &c:s1) f1[c-'a']++;
        int left=0;
        for(int right=0;right<m;right++){
            f2[s2[right]-'a']++;
            if((right-left+1)>n){
                f2[s2[left]-'a']--;
                left++;
            }
            if(f1==f2) return true;
        }
        return false;
    }
};