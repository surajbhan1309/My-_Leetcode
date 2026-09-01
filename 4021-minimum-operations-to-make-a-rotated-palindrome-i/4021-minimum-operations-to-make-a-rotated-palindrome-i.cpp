class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int ans=INT_MAX;
        for(int r=0;r<n;r++){
            int cost=r;
            for(int i=0;i<n/2;i++){
                char left=s[(r+i)%n];
                char right=s[(n+r-i-1)%n];
                int diff=abs(left-right);
                cost+=min(diff,26-diff);
            }
            ans=min(ans,cost);
        }
        return ans;
    }
};