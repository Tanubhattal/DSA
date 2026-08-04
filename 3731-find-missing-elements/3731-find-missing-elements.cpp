class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min_val = nums[0];
        int max_val = nums[0];
        unordered_set<int> present;
        for (int num : nums) {
            present.insert(num);
            min_val = min(min_val, num);
            max_val = max(max_val, num);
        }
        vector<int> result;
        for (int i = min_val; i <= max_val; ++i) {
            if (present.find(i) == present.end()) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};