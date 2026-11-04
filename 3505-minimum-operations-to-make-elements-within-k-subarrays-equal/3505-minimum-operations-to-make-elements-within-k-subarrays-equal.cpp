
class Solution {
public:
    multiset<long long> low, high;
    long long sumLow = 0, sumHigh = 0;
    void add(int num) {
        if (low.empty() || num <= *low.rbegin()) {
            low.insert(num);
            sumLow += num;
        } else {
            high.insert(num);
            sumHigh += num;
        }
        balance();
    }
    void remove(int num) {
        auto it = low.find(num);
        if (it != low.end()) {
            low.erase(it);
            sumLow -= num;
        } else {
            it = high.find(num);
            high.erase(it);
            sumHigh -= num;
        }
        balance();
    }
    void balance() {
        while (low.size() > high.size() + 1) {
            auto it = prev(low.end());
            long long val = *it;
            low.erase(it);
            sumLow -= val;
            high.insert(val);
            sumHigh += val;
        }
        while (low.size() < high.size()) {
            auto it = high.begin();
            long long val = *it;
            high.erase(it);
            sumHigh -= val;
            low.insert(val);
            sumLow += val;
        }
    }
    long long getCost() {
        long long median = *low.rbegin();
        return median * low.size() - sumLow
             + sumHigh - median * high.size();
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> cost(n - x + 1);
        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= x) {
                remove(nums[i - x]);
            }
            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }
        const long long INF = 1e18;
        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }
        return dp[n][k];
    }
};
