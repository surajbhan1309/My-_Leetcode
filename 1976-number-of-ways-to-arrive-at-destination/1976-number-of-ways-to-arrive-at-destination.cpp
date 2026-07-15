class Solution {
public:
    typedef pair<long long, int> P;
    int M = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<long long> result(n, LLONG_MAX);
        vector<int> pathcount(n, 0);

        result[0] = 0;
        pathcount[0] = 1;
        pq.push({0, 0}); // {time, node}

        while (!pq.empty()) {
            long long currTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            if (currTime > result[currNode]) continue;

            for (auto &vec : adj[currNode]) {
                int nbr = vec.first;
                int roadTime = vec.second;

                if (currTime + roadTime < result[nbr]) {
                    result[nbr] = currTime + roadTime;
                    pq.push({result[nbr], nbr});
                    pathcount[nbr] = pathcount[currNode];
                } else if (currTime + roadTime == result[nbr]) {
                    pathcount[nbr] = (pathcount[nbr] + pathcount[currNode]) % M;
                }
            }
        }

        return pathcount[n - 1];
    }
};
