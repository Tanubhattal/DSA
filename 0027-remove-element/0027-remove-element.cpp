class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int right = 0;
        for (int left = 0; left < nums.size(); left++) {
            if (nums[left] != val) {
                nums[right] = nums[left];
                right++;
            }
        }

        return right;
    }
};