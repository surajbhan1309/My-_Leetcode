class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>f(26,0);
        if(s.size()!=t.size()) return false;
        for(auto &c:s){
            f[c-'a']++;
        }
        for(auto &c:t){
            f[c-'a']--;
        }
        for(auto &count:f){
            if(count!=0){
                return false;
            }
        }
        return true;
    }
};