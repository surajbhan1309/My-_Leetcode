// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         int n=numCourses;
//         vector<vector<int>>adj(n);
//         int count=0;
//         vector<int>indeg(n,0);
//         for(auto x:prerequisites){
//             adj[x[1]].push_back(x[0]);
//             indeg[x[0]]++;
//         }
//         queue<int>q;
//         for(int i=0;i<n;i++){
//             if(indeg[i]==0){
//                 q.push(i);
//             }
//         }
//         while(!q.empty()){
//             int u=q.front();
//             q.pop();
//             count++;

//             for(auto v:adj[u]){
//                 indeg[v]--;
//                 if(indeg[v]==0){
//                     q.push(v);
//                 }
//             }
//         }
//         return count==n;
//     }
// };

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1; // visiting

        for (int next : adj[node]) {
            if (vis[next] == 1) return false; // cycle

            if (vis[next] == 0) {
                if (!dfs(next, adj, vis))
                    return false;
            }
        }

        vis[node] = 2; // done
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto &p : prerequisites)
            adj[p[0]].push_back(p[1]);

        vector<int> vis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (dfs(i, adj, vis)==false)
                    return false;
            }
        }

        return true;
    }
};