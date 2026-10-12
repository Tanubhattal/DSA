class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bit_count(30, 0);
        for (int x : nums) {
            for (int i = 0; i < 30; ++i) {
                if ((x >> i) & 1) {
                    bit_count[i]++;
                }
            }
        }
        vector<long long> new_nums(nums.size(), 0);
        for (int i = 0; i < 30; ++i) {
            for (int j = 0; j < bit_count[i]; ++j) {
                new_nums[j] |= (1 << i);
            }
        }
        long long ans = 0;
        long long mod = 1e9 + 7;
        sort(new_nums.rbegin(), new_nums.rend());
        for (int i = 0; i < k; ++i) {
            ans = (ans + (new_nums[i] * new_nums[i]) % mod) % mod;
        }
        return ans;
    }
};