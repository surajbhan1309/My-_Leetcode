class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto flight:flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        queue<pair<int,int>>q;
        q.push({src,0});
        vector<int>minCost(n,INT_MAX);
        int steps=0;
        while(!q.empty() && steps<=k ){
            int size=q.size();
            while(size--){
                auto [currNode,cost]=q.front();
                q.pop();
                for(auto& [nbr,price]:adj[currNode]){
                    if(price+cost<minCost[nbr]){
                        minCost[nbr]=price+cost;
                        q.push({nbr,minCost[nbr]});
                    }
                }
            }        
            steps++;
            
        }
        if(minCost[dst]==INT_MAX){
            return -1;
        }
        return minCost[dst];
    }
};