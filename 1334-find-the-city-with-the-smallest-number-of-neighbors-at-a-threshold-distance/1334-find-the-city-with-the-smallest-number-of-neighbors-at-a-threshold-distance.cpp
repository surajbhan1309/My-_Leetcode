class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        int ans = -1;
        int minCount = n + 1;

        for (int i = 0; i < n; i++) {
            vector<int> dist(n, 1e9);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            
            dist[i] = 0;
            pq.push({0, i});

            while (!pq.empty()) {
                auto [d, node] = pq.top();
                pq.pop();

                if (d > dist[node]) continue;

                for (const auto& [nbr, w] : graph[node]) {
                    if (d + w < dist[nbr]) {
                        dist[nbr] = d + w;
                        pq.push({dist[nbr], nbr});
                    }
                }
            }

            int count = 0;
            for (int d : dist) {
                if (d <= distanceThreshold) count++;
            }

            if (count <= minCount) {
                minCount = count;
                ans = i;
            }
        }

        return ans;
    }
};
