class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int,int>mp;
        for(auto &x:ransomNote){
            mp[x]++;
        }
        for(auto &x:magazine){
            mp[x]--;
        }
        int n=ransomNote.size();
        for(int i=0;i<n;i++){
            if(mp[ransomNote[i]]>=1) return false;
        }
        return true;
    }
};