class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto it : count) {
            bucket[it.second].push_back(it.first);
        }
        vector<int> ans;
        for (int freq = nums.size(); freq >= 1 && ans.size() < k; freq--) {
            for (int num : bucket[freq]) {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};