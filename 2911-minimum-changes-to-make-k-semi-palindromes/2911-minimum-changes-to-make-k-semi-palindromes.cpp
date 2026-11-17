class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> v(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                int min_cost = INT_MAX;
                for (int d = 1; d < len; ++d) {
                    if (len % d == 0) {
                        int cost = 0;
                        for (int offset = 0; offset < d; ++offset) {
                            int l = i + offset;
                            int r = i + len - d + offset;
                            while (l < r) {
                                if (s[l] != s[r]) {
                                    cost++;
                                }
                                l += d;
                                r -= d;
                            }
                        }
                        min_cost = min(min_cost, cost);
                    }
                }
                v[i][j] = min_cost;
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[0][0] = 0;
        for (int parts = 1; parts <= k; ++parts) {
            for (int i = 1; i <= n; ++i) {
                for (int j = (parts - 1) * 2; j < i - 1; ++j) {
                    dp[i][parts] = min(dp[i][parts], dp[j][parts - 1] + v[j][i - 1]);
                }
            }
        }
        
        return dp[n][k];
    }
};