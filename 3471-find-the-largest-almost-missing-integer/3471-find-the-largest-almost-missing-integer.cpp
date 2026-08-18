class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) {
            int freq[51] = {};
            for (int x : nums) {
                freq[x]++;
            }
            int ans = -1;
            for (int x = 0; x <= 50; x++) {
                if (freq[x] == 1) {
                    ans = x;
                }
            }
            return ans;
        }
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        int freq[51] = {};
        for (int x : nums) {
            freq[x]++;
        }
        int ans = -1;
        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }
        return ans;
    }
};