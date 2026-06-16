class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(auto &x:prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(!dfs(i,adj,vis)){ // can be written as dfs(i,adj,vis)==false
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        for(auto &nbr:adj[node]){
            if(vis[nbr]==1) return false; // cycle detect
            if(vis[nbr]==0){
                if(!dfs(nbr,adj,vis)){
                    return false;
                }
            }
        }
        vis[node]=2;
        return true;
    }
};