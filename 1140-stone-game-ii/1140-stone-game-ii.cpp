class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int m) {
        if (i >= n)
            return 0;

        if (dp[i][m] != -1)
            return dp[i][m];

        int ans = 0;

        for (int x = 1; x <= 2 * m && i + x <= n; x++) {
            int opponent = solve(i + x, max(m, x));

            ans = max(ans, suffix[i] - opponent);
        }

        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};