class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n, 1e9); 
        int min_len_sum = 1e9;  
        int min_len_so_far = 1e9; 
        int left = 0;
        int current_sum = 0;
        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            while (current_sum > target && left <= right) {
                current_sum -= arr[left];
                left++;
            }
            if (current_sum == target) {
                int curr_len = right - left + 1;
                if (left > 0 && dp[left - 1] != 1e9) {
                    min_len_sum = min(min_len_sum, dp[left - 1] + curr_len);
                }
                min_len_so_far = min(min_len_so_far, curr_len);
            }
            dp[right] = min_len_so_far;
        }
        return min_len_sum == 1e9 ? -1 : min_len_sum;
    }
};