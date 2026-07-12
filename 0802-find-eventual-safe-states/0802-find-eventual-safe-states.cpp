class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>revgraph(n);
        vector<int>outdegree(n);
        vector<int>ans;
        queue<int>q;

        for(int i=0;i<n;i++){
            outdegree[i]=graph[i].size();
            if(outdegree[i]==0) q.push(i);
            for(int nbr:graph[i]){
                revgraph[nbr].push_back(i);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:revgraph[u]){
                outdegree[v]--;
                if(outdegree[v]==0) q.push(v);
            }
        }
        for(int i=0;i<n;i++){
            if(outdegree[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};