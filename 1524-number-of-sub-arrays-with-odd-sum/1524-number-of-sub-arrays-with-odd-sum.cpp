class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int oddCount = 0, evenCount = 1;
        int prefixSum = 0, ans = 0;
        int MOD = 1e9 + 7;

        for (int x : arr) {
            prefixSum += x;
            if (prefixSum % 2 != 0) {
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