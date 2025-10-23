#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // adjacency list: u -> (v, w)
        vector<vector<pair<int,int>>> adj(n+1);
        for (auto &time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        // min-heap: {time, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, INT_MAX);

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [currTime, u] = pq.top();
            pq.pop();

            if (currTime > dist[u]) continue;

            for (auto [v, w] : adj[u]) {
                if (currTime + w < dist[v]) {
                    dist[v] = currTime + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
