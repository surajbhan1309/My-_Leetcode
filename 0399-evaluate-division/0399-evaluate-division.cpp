class Solution {
private:
    double dfs(const string& curr, const string& target, 
               unordered_map<string, unordered_map<string, double>>& graph, 
               unordered_set<string>& visited) {
        // Return -1.0 if either node is missing from the graph
        if (graph.find(curr) == graph.end() || graph.find(target) == graph.end()) {
            return -1.0;
        }
        // Base case: target node is reached
        if (curr == target) {
            return 1.0;
        }
        
        visited.insert(curr);
        
        // Explore all connected neighbor variables
        for (const auto& neighbor : graph[curr]) {
            string nextNode = neighbor.first;
            double weight = neighbor.second;
            
            if (visited.find(nextNode) == visited.end()) {
                double res = dfs(nextNode, target, graph, visited);
                if (res != -1.0) {
                    return weight * res; // Accumulate path product
                }
            }
        }
        
        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        
        // Step 1: Build the directed weighted graph from equations
        for (size_t i = 0; i < equations.size(); ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            
            graph[u][v] = val;
            graph[v][u] = 1.0 / val; // Reverse relation
        }
        
        // Step 2: Resolve each evaluation query
        vector<double> results;
        for (const auto& query : queries) {
            string start = query[0];
            string target = query[1];
            unordered_set<string> visited;
            
            results.push_back(dfs(start, target, graph, visited));
        }
        
        return results;
    }
};
