class Solution {
private:
    class Stack {
    public:
        int values[26] = {0}; 
        int top = 0;
        
        void push(int val) {
            values[top++] = val; 
        }
        
        int pop() {
            top--; 
            return values[top];
        }
        
        bool isEmpty() {
            return top == 0; 
        }
    };

    void dfs(int v, const vector<vector<bool>>& graph, Stack& stack, vector<bool>& visited) {
        if (!visited[v]) {
            visited[v] = true; 
            for (int i = 0; i < 26; i++) {
                if (graph[v][i] && !visited[i]) {
                    dfs(i, graph, stack, visited);
                }
            }
            stack.push(v);
        }
    }
    
    void dfs(int v, const vector<vector<bool>>& graph, vector<int>& batches, int batch, vector<int>& degree) {
        if (batches[v] < 0) {
            batches[v] = batch; 
            for (int i = 0; i < 26; i++) {
                if (graph[i][v]) {
                    dfs(i, graph, batches, batch, degree); 
                }  
            }
        } else {
            if (batches[v] != batch) {
                degree[batches[v]] += 1;
            }
        }
    }

public:
    vector<string> maxNumOfSubstrings(string S) {
        // Some pre-compute in order to build the graph in O(N) time
        vector<int> mins(26, INT_MAX); 
        vector<int> maxs(26, -1); 
        vector<bool> exists(26, false); 
        
        int len = S.length();
        vector<vector<int>> prefixSum(len + 1, vector<int>(26, 0)); 
        
        for (int i = 0; i < len; i++) {
            // Copy previous prefix counts
            for (int j = 0; j < 26; j++) {
                prefixSum[i + 1][j] = prefixSum[i][j];
            }
            int charIdx = S[i] - 'a';
            prefixSum[i + 1][charIdx] += 1; 
            mins[charIdx] = min(mins[charIdx], i); 
            maxs[charIdx] = max(maxs[charIdx], i); 
            exists[charIdx] = true; 
        }
        
        // Build graph, using adjacency matrix
        vector<vector<bool>> graph(26, vector<bool>(26, false));
        for (int i = 0; i < 26; i++) {
            if (exists[i]) {
                for (int j = 0; j < 26; j++) {
                    if (prefixSum[maxs[i] + 1][j] - prefixSum[mins[i]][j] > 0) {
                        graph[i][j] = true; 
                    }
                }
            }
        }
    
        // Kosaraju algorithm to find scc
        Stack stack; 
        vector<bool> visited(26, false); 
        for (int i = 0; i < 26; i++) {
            if (exists[i] && !visited[i]) {
                dfs(i, graph, stack, visited);
            }
        }
        
        int batch = 0; // 'id' of each SCC
        vector<int> batches(26, -1); 
        vector<int> degree(26, 0);  // out-degree of each SCC
        
        while (!stack.isEmpty()) {
            int v = stack.pop(); 
            if (batches[v] < 0) {
                dfs(v, graph, batches, batch, degree);
                batch++; 
            }
        }
        
        vector<string> res; 
        for (int i = batch - 1; i >= 0; i--) {
            if (degree[i] == 0) {
                int min_val = INT_MAX, max_val = -1; 
                for (int j = 0; j < 26; j++) {
                    if (batches[j] == i) {
                        min_val = min(mins[j], min_val); 
                        max_val = max(maxs[j], max_val); 
                    }
                }
                res.push_back(S.substr(min_val, max_val - min_val + 1));
            }
        }
        
        return res; 
    }
};
