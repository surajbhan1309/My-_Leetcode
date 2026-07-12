class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,0);
        queue<int>q;

        for(int i=0;i<n;i++){
            if(color[i]==0){
                color[i]=1;
                q.push(i);
            }
            else{
                continue;
            }
            while(!q.empty()){
                int curr=q.front();
                q.pop();

                for(int nbr:graph[curr]){
                    if(!color[nbr]){
                        color[nbr]=-color[curr];
                        q.push(nbr);
                    }
                    else if(color[nbr]==color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};