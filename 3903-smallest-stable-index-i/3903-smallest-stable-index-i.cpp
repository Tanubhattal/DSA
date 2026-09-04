class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int max_val = *max_element(nums.begin(), nums.begin() + i + 1);
            int min_val = *min_element(nums.begin() + i, nums.end());
            int instability_score = max_val - min_val;
            if (instability_score <= k) {
                return i;
            }
        }
        return -1;
    }
};