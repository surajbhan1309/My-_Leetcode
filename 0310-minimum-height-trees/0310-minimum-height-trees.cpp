class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};

        queue<int> q;
        vector<vector<int>> adj(n);
        vector<int> Indeg(n, 0);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            Indeg[e[0]]++;
            Indeg[e[1]]++;
        }

        for (int i = 0; i < n; i++) {
            if (Indeg[i] == 1) {
                q.push(i);
            }
        }

        while (n > 2) {
            int size = q.size();
            n -= size;
            while (size--) {
                int node = q.front();
                q.pop();

                for (int j = 0; j < adj[node].size(); j++) {
                    Indeg[adj[node][j]]--;
                    if (Indeg[adj[node][j]] == 1) {
                        q.push(adj[node][j]);
                    }
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};