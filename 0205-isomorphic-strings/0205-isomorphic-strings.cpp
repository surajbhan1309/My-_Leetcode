class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int>v1;
        unordered_map<char,int>v2;
        for(int i=0;i<s.size();i++){
            if(v1.find(s[i])==v1.end()){
                v1[s[i]]=i;
            }
            if(v2.find(t[i])==v1.end()){
                v2[t[i]]=i;
            }
            if(v1[s[i]]!=v2[t[i]]) return false;
        }
        return true;
    }
};