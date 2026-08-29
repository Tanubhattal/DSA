class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {nums[i], i};
        }
        sort(pairs.begin(), pairs.end());
        vector<int> ans(n);
        int l = 0;
        while (l < n) {
            int r = l + 1;
            while (r < n && pairs[r].first - pairs[r - 1].first <= limit) {
                r++;
            }
            vector<int> indices;
            for (int i = l; i < r; ++i) {
                indices.push_back(pairs[i].second);
            }
            sort(indices.begin(), indices.end());
            for (int i = l; i < r; ++i) {
                ans[indices[i - l]] = pairs[i].first;
            }
            l = r;
        }
        return ans;
    }
};