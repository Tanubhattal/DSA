class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<vector<int>> new_adj(n);
        vector<int> latest_char(26, -1);

        auto build_new_tree = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            int prev_node = latest_char[c];
            int new_parent = (prev_node != -1) ? prev_node : parent[u];
            if (new_parent != -1) {
                new_adj[new_parent].push_back(u);
            }

            int old_val = latest_char[c];
            latest_char[c] = u;
            for (int v : adj[u]) {
                self(self, v);
            }
            latest_char[c] = old_val;
        };

        build_new_tree(build_new_tree, 0);

        vector<int> ans(n, 0);
        auto calc_sizes = [&](auto& self, int u) -> int {
            int sz = 1;
            for (int v : new_adj[u]) {
                sz += self(self, v);
            }
            return ans[u] = sz;
        };

        calc_sizes(calc_sizes, 0);
        return ans;
    }
};