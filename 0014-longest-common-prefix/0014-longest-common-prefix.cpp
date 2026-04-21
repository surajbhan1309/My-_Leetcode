class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        sort(strs.begin(), strs.end());
        
        int n = strs.size();   // number of strings
        string ans = "";
        
        for(int i = 0; i < strs[0].size(); i++){
            if(strs[0][i] == strs[n-1][i]) ans.push_back(strs[0][i]);
            else break;
        }
        return ans;
    }
};