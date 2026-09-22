class Solution {
public:
    struct Node {
        int freqs[5] = {0};
        int totalProduct = 1;
    };

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<Node> tree(4 * n);

        auto merge = [&](const Node& left, const Node& right) {
            Node res;
            res.totalProduct = (left.totalProduct * right.totalProduct) % k;
            
            for (int i = 0; i < k; ++i) {
                res.freqs[i] = left.freqs[i];
            }
            
            for (int i = 0; i < k; ++i) {
                if (right.freqs[i] > 0) {
                    int combined_val = (left.totalProduct * i) % k;
                    res.freqs[combined_val] += right.freqs[i];
                }
            }
            
            return res;
        };

        auto build = [&](auto self, int node, int start, int end) -> void {
            if (start == end) {
                tree[node].totalProduct = nums[start] % k;
                tree[node].freqs[nums[start] % k] = 1;
                return;
            }
            int mid = start + (end - start) / 2;
            self(self, 2 * node, start, mid);
            self(self, 2 * node + 1, mid + 1, end);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        };

        auto update = [&](auto self, int node, int start, int end, int idx, int val) -> void {
            if (start == end) {
                for (int i = 0; i < k; ++i) tree[node].freqs[i] = 0;
                tree[node].totalProduct = val % k;
                tree[node].freqs[val % k] = 1;
                return;
            }
            int mid = start + (end - start) / 2;
            if (idx <= mid) {
                self(self, 2 * node, start, mid, idx, val);
            } else {
                self(self, 2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        };

        auto query_tree = [&](auto self, int node, int start, int end, int l, int r) -> Node {
            if (l <= start && end <= r) {
                return tree[node];
            }
            int mid = start + (end - start) / 2;
            
            if (r <= mid) {
                return self(self, 2 * node, start, mid, l, r);
            }
            if (l > mid) {
                return self(self, 2 * node + 1, mid + 1, end, l, r);
            }
            
            Node leftRes = self(self, 2 * node, start, mid, l, r);
            Node rightRes = self(self, 2 * node + 1, mid + 1, end, l, r);
            return merge(leftRes, rightRes);
        };

        build(build, 1, 0, n - 1);

        vector<int> result;
        result.reserve(queries.size());
        
        for (const auto& q : queries) {
            int index = q[0], value = q[1], start_idx = q[2], x = q[3];
            update(update, 1, 0, n - 1, index, value);
            nums[index] = value;
            
            if (start_idx >= n) {
                 result.push_back(0);
                 continue;
            }

            Node res_node = query_tree(query_tree, 1, 0, n - 1, start_idx, n - 1);
            result.push_back(res_node.freqs[x]);
        }

        return result;
    }
};