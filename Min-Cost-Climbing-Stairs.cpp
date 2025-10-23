class Solution {
public:

    int solve(vector<int>&cost,int n){
        vector<int>dp(n+1);
        int prev1=cost[0];
        int prev2=cost[1];
        int curr=0;

        for(int i=2;i<n;i++){
            curr=cost[i]+min(prev1,prev2);
            prev1=prev2;
            prev2=curr;
            curr++;
        }
        return min(prev1,prev2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        return solve(cost,n);
        
    }
};