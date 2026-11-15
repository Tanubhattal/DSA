class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int min_sum = INT_MAX;
        
        for (int length = l; length <= r; ++length) {
            int current_sum = 0;
            for (int i = 0; i < length; ++i) {
                current_sum += nums[i];
            }
            if (current_sum > 0) {
                min_sum = min(min_sum, current_sum);
            }
            
            for (int i = length; i < n; ++i) {
                current_sum += nums[i] - nums[i - length];
                if (current_sum > 0) {
                    min_sum = min(min_sum, current_sum);
                }
            }
        }
        
        return min_sum == INT_MAX ? -1 : min_sum;
    }
};