class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,0);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!color[i]){
                color[i]=1;
                q.push(i);
            }
            else{
                continue;
            }
            while(!q.empty()){
                auto node=q.front();
                q.pop();

                for(auto &nbr:graph[node]){
                    if(!color[nbr]){
                        color[nbr]=-color[node];
                        q.push(nbr);
                    }
                    else if(color[nbr]==color[node]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};