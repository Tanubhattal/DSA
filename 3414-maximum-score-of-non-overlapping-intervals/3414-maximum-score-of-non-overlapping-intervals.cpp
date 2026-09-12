class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> order(n);
        for (int i = 0; i < n; ++i) {
            order[i] = i;
        }
        sort(order.begin(), order.end(), [&](int a, int b) {
            return intervals[a][1] < intervals[b][1];
        });
        vector<int> rights(n);
        for (int i = 0; i < n; ++i) {
            rights[i] = intervals[order[i]][1];
        }
        using State = pair<long long, vector<int>>;
        vector<State> prev(n + 1, {0LL, {}});
        for (int k = 0; k < 4; ++k) {
            vector<State> cur(n + 1, {0LL, {}});
            for (int p = 1; p <= n; ++p) {
                int i = order[p - 1];
                long long l = intervals[i][0];
                long long w = intervals[i][2];
                int j = lower_bound(rights.begin(), rights.end(), l) - rights.begin();
                long long score = prev[j].first;
                vector<int> ids = prev[j].second;
                ids.push_back(i);
                sort(ids.begin(), ids.end());
                State take = {score - w, ids};
                cur[p] = min(take, cur[p - 1]);
            }
            prev = move(cur);
        }
        return prev[n].second;
    }
};