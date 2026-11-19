class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) return 0;
        sort(nums.begin(), nums.end());
        int opt1 = nums[n - 1] - nums[2]; 
        int opt2 = nums[n - 2] - nums[1]; 
        int opt3 = nums[n - 3] - nums[0]; 
        return min({opt1, opt2, opt3});
    }
};