class Solution {
public:
    void dfs(int u,vector<vector<int>>& adj,vector<int>& disc,vector<int>& low,vector<int>& parent,vector<vector<int>>& bridges)
    {
        static int time = 0;
        low[u] = disc[u] = time++;
        for(int v:adj[u])
        {
            if(disc[v] == -1)
            {
                parent[v] = u;
                dfs(v,adj,disc,low,parent,bridges);
                low[u] = min(low[u],low[v]);
                if(low[v]>disc[u])
                {
                    bridges.push_back({u,v});
                }
            }
            else if(v != parent[u])
            {
                low[u] = min(low[u],disc[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto i:connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> disc(n,-1), low(n,-1), parent(n,-1);
        vector<vector<int>> bridges;
        for(int i=0;i<n;i++)
        {
            if(disc[i]==-1)
            {
                dfs(i,adj,disc,low,parent,bridges);
            }
        }
        return bridges;
    }
};