#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& is_suspicious) {
        is_suspicious[u] = true;
        for (int v : adj[u]) {
            if (!is_suspicious[v]) {
                dfs(v, adj, is_suspicious);
            }
        }
    }
        vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> is_suspicious(n, false);
        dfs(k, adj, is_suspicious);

        for (const auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            if (!is_suspicious[u] && is_suspicious[v]) {
                vector<int> all_methods(n);
                for (int i = 0; i < n; ++i) {
                    all_methods[i] = i;
                }
                return all_methods;
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!is_suspicious[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};