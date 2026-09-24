class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int current_num = nums[i];
            int digit_sum = 0;
            while (current_num > 0) {
                digit_sum += current_num % 10;
                current_num /= 10;
            }
            if (digit_sum == i) {
                return i;
            }
        }
        return -1;
    }
};