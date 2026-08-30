class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int minIdx = 0;
        int maxIdx = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        int i = min(minIdx, maxIdx);
        int j = max(minIdx, maxIdx);
        int bothFront = j + 1;
        int bothBack = n - i;
        int frontAndBack = (i + 1) + (n - j);
        return min({bothFront, bothBack, frontAndBack});
    }
};