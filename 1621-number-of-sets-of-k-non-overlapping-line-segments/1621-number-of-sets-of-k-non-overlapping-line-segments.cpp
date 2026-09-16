class Solution {
    int MOD = 1e9 + 7;
    int memo[1005][1005][2];
    int dp(int i, int k, bool isStart, int n) {
        if (k == 0) return 1;
        if (i == n) return 0;
        if (memo[i][k][isStart] != -1) return memo[i][k][isStart];
        long long ways = dp(i + 1, k, isStart, n); 
        if (isStart) {
            ways = (ways + dp(i + 1, k, false, n)) % MOD;
        } else {
            ways = (ways + dp(i, k - 1, true, n)) % MOD;
        }
        return memo[i][k][isStart] = ways;
    }
public:
    int numberOfSets(int n, int k) {
        memset(memo, -1, sizeof(memo));
        return dp(0, k, true, n);
    }
};