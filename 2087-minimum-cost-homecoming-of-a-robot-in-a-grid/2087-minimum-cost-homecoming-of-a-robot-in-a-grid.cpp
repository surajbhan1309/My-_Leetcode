class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans = 0;
        int i = startPos[0];
        int j = startPos[1];
        int x = homePos[0];
        int y = homePos[1];
        
        // Move vertically row by row towards home
        while (i != x) {
            i += (i < x) ? 1 : -1;
            ans += rowCosts[i];
        }
        
        // Move horizontally column by column towards home
        while (j != y) {
            j += (j < y) ? 1 : -1;
            ans += colCosts[j];
        }
        
        return ans;
    }
};
