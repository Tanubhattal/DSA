class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<unordered_map<int, int>> dist(n);
        pq.push({0, 0, 1});
        dist[0][1] = 0;
        while (!pq.empty()) {
            auto [w, u, count] = pq.top();
            pq.pop();
            if (u == n - 1) {
                return w;
            }
            if (w > dist[u][count]) {
                continue;
            }
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                int next_count = (labels[u] == labels[v]) ? count + 1 : 1;
                if (next_count <= k) {
                    if (dist[v].find(next_count) == dist[v].end() || w + weight < dist[v][next_count]) {
                        dist[v][next_count] = w + weight;
                        pq.push({w + weight, v, next_count});
                    }
                }
            }
        }
        return -1;
    }
};