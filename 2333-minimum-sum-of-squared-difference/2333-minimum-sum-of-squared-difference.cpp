class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long totalOps = (long long)k1 + k2;
        unordered_map<int, long long> diffCount;
        int maxDiff = 0;
        for (int i = 0; i < n; ++i) {
            int d = abs(nums1[i] - nums2[i]);
            diffCount[d]++;
            maxDiff = max(maxDiff, d);
        }
        for (int d = maxDiff; d > 0 && totalOps > 0; --d) {
            if (diffCount[d] == 0) continue;
            long long opsNeeded = diffCount[d];
            long long opsToUse = min(totalOps, opsNeeded);
            diffCount[d] -= opsToUse;
            diffCount[d - 1] += opsToUse;
            totalOps -= opsToUse;
        }
        long long ans = 0;
        for (auto& [d, count] : diffCount) {
            if (d > 0 && count > 0) {
                ans += (long long)d * d * count;
            }
        } 
        return ans;
    }
};