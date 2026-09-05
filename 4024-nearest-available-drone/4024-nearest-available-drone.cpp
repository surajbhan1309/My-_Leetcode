class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n=drones.size();
        int ans=-1;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int man=abs(target[0]-drones[i][0])+abs(target[1]-drones[i][1]);
            if(man<=drones[i][2]){
                if(man<mini){
                    ans=i;
                    mini=man;
                }
            }
        }
        return ans;
    }
};