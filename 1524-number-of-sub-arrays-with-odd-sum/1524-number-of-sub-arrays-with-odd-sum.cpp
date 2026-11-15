class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long oddCount = 0, evenCount = 1;
        long long currentSum = 0;
        long long ans = 0;
        int MOD = 1e9 + 7;
        for (int x : arr) {
            currentSum += x;
            if (currentSum % 2 != 0) {
                ans = (ans + evenCount) % MOD;
                oddCount++;
            } else {
                ans = (ans + oddCount) % MOD;
                evenCount++;
            }
        }
        return ans;
    }
};