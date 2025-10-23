class Solution {
public:
    int longestBalanced(string s) {
        unordered_map<char,int>window;
        int n=s.size();
        int res=0;
        for(int i=0;i<n;i++){
            vector<int>Vmap(26,0);
            for(int j=i;j<n;j++){
                Vmap[s[j]-'a']++;
            int mini=INT_MAX;
            int maxi=INT_MIN;
            for(int &x:Vmap){
                if(x>0){
                    mini=min(mini,x);
                    maxi=max(maxi,x);
                }
            }
            if(maxi==mini){
                res=max(res,j-i+1);
                }
            }
        }
        return res;
        
    }
};