class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>indeg(n,0);
        vector<int>topo;
        vector<vector<int>>adj(n);
        queue<int>q;
        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
            indeg[x[0]]++;
        }
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            topo.push_back(u);
            for(auto v:adj[u]){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }
        return topo.size()==n;
    }
};