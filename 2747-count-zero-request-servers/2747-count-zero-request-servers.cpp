class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        vector<pair<int, int>> sortedQueries(m);
        for (int i = 0; i < m; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<int> count(n + 1, 0);
        int activeServers = 0;
        int l = 0, r = 0;
        int numLogs = logs.size();

        for (int i = 0; i < m; ++i) {
            int qTime = sortedQueries[i].first;
            int idx = sortedQueries[i].second;
            int startTime = qTime - x;

            while (r < numLogs && logs[r][1] <= qTime) {
                int serverId = logs[r][0];
                if (count[serverId] == 0) {
                    activeServers++;
                }
                count[serverId]++;
                r++;
            }

            while (l < numLogs && logs[l][1] < startTime) {
                int serverId = logs[l][0];
                count[serverId]--;
                if (count[serverId] == 0) {
                    activeServers--;
                }
                l++;
            }

            ans[idx] = n - activeServers;
        }

        return ans;
    }
};