class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        int left = 0;
        int maxLen = 0;
        for (int right = 0; right < nums.size(); ++right) {
            count[nums[right]]++;
            while (count[nums[right]] > k) {
                count[nums[left]]--;
                left++;
            }
            maxLen = std::max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};