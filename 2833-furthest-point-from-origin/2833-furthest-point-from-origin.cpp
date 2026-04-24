class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.size();
        int lc=0;
        int rc=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='L') lc++;
            else if(moves[i]=='R') rc++;
            else c++;
        }
        int diff=abs(lc-rc);
        return diff+c;

        
        
    }
};