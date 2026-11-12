class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxLength = 1;
        int incLen = 1;
        int decLen = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] > nums[i]) {
                incLen++;
                decLen = 1; 
            } else if (nums[i + 1] < nums[i]) {
                decLen++;
                incLen = 1; 
            } else {
                incLen = 1;
                decLen = 1; 
            }
            maxLength = max({maxLength, incLen, decLen});
        }
        return maxLength;
    }
};