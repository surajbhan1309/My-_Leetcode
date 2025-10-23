class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        long long sum=0;

        for(int i=0;i<n;i++){
            unordered_map<char,int>vMap;
            for(int j=i;j<n;j++){
                vMap[s[j]]++;
                int mini=INT_MAX;
                int maxi=INT_MIN;
                for(auto &x:vMap){
                    mini=min(mini,x.second);
                    maxi=max(maxi,x.second);
                }
                sum+=(maxi-mini);
            }
        }
        return sum;
        
    }
};