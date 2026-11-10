class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, -1);
        dp[0] = 0;
        for (int j = 1; j <= n; ++j) {
            long long min_cost = -1;
            for (int k = 1; k <= 3; ++k) {
                int i = j - k;
                if (i >= 0 && dp[i] != -1) {
                    long long cost = dp[i] + costs[j - 1] + (long long)(j - i) * (j - i);
                    if (min_cost == -1 || cost < min_cost) {
                        min_cost = cost;
                    }
                }
            }
            dp[j] = min_cost;
        }
        return dp[n];
    }
};