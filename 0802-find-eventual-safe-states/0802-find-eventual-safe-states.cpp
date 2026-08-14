class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>ans;
        vector<vector<int>>revgraph(n);
        queue<int>q;
        vector<int>outdeg(n);

        for(int i=0;i<n;i++){
            outdeg[i]=graph[i].size();
            if(outdeg[i]==0) q.push(i);
            for(auto &nbr:graph[i]){
                revgraph[nbr].push_back(i);
            }
        }
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto &v:revgraph[node]){
                outdeg[v]--;
                if(outdeg[v]==0) q.push(v);
            }
        }
        for(int i=0;i<n;i++){
            if(outdeg[i]==0) ans.push_back(i);
        }
        return ans;
    }
};