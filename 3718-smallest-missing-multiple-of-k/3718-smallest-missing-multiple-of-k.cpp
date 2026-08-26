class Solution {
public:
    int missingMultiple(std::vector<int>& nums, int k) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int multiple = k;
        while (numSet.count(multiple)) {
            multiple += k;
        }
        return multiple;
    }
};