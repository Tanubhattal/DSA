class Solution {
public:
    int sumCounts(vector<int>& nums) {
        long long MOD = 1e9 + 7;
        int n = nums.size();
        struct Node {
            long long sumSq = 0;
            long long sum = 0;
            long long lazy = 0;
        };
        vector<Node> tree(4 * n);

        auto apply = [&](int node, long long val, int l, int r) {
            long long len = (r - l + 1);
            tree[node].sumSq = (tree[node].sumSq + 2 * val * tree[node].sum + val * val % MOD * len) % MOD;
            tree[node].sum = (tree[node].sum + val * len) % MOD;
            tree[node].lazy = (tree[node].lazy + val) % MOD;
        };

        auto push = [&](int node, int l, int r) {
            if (tree[node].lazy != 0) {
                int mid = l + (r - l) / 2;
                apply(2 * node, tree[node].lazy, l, mid);
                apply(2 * node + 1, tree[node].lazy, mid + 1, r);
                tree[node].lazy = 0;
            }
        };

        auto update = [&](auto& self, int node, int l, int r, int ql, int qr, long long val) -> void {
            if (ql > r || qr < l) return;
            if (ql <= l && r <= qr) {
                apply(node, val, l, r);
                return;
            }
            push(node, l, r);
            int mid = l + (r - l) / 2;
            self(self, 2 * node, l, mid, ql, qr, val);
            self(self, 2 * node + 1, mid + 1, r, ql, qr, val);
            tree[node].sum = (tree[2 * node].sum + tree[2 * node + 1].sum) % MOD;
            tree[node].sumSq = (tree[2 * node].sumSq + tree[2 * node + 1].sumSq) % MOD;
        };

        unordered_map<int, int> lastPos;
        long long current_ans = 0;

        for (int j = 0; j < n; ++j) {
            int prev = -1;
            if (lastPos.count(nums[j])) {
                prev = lastPos[nums[j]];
            }
            lastPos[nums[j]] = j;

            update(update, 1, 0, n - 1, prev + 1, j, 1);
            current_ans = (current_ans + tree[1].sumSq) % MOD;
        }

        return current_ans;
    }
};