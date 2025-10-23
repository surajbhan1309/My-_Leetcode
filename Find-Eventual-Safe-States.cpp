class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<bool>isVisited(V,false);
        vector<bool>inRec(V,false);

        for(int i=0;i<V;i++){
            if(!isVisited[i]){
                isCycleDFS(graph,i,isVisited,inRec);
            }
        }
        vector<int>safeNodes;
        for(int i=0;i<V;i++){
            if(!inRec[i]){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
        
    }
    bool isCycleDFS(vector<vector<int>>& graph,int i,vector<bool>&isVisited,vector<bool>&inRec){
        isVisited[i]=true;
        inRec[i]=true;
        for(auto &v:graph[i]){
            if(!isVisited[v] && isCycleDFS(graph,v,isVisited,inRec)){
                return true;
            }
            else if(inRec[v]==true){
                return true;
            }

        }
        inRec[i]=false;
        return false;
    }
};