class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));

        dp[0][0] = true;

        for (int cnt = 0; cnt < 3; cnt++) {
            for (int x = 0; x < MAXX; x++) {
                if (!dp[cnt][x]) continue;

                for (int v : nums) {
                    dp[cnt + 1][x ^ v] = true;
                }
            }
        }

        int ans = 0;

        for (bool ok : dp[3])
            if (ok) ans++;

        return ans;
    }
};