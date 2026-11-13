class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long ops = 0;
        deque<int> dq;
        
        for (int l = n - 1, r = n - 1; l >= 0; --l) {
            while (!dq.empty() && nums[dq.back()] < nums[l]) {
                int idx = dq.back();
                dq.pop_back();
                int next_idx = dq.empty() ? r + 1 : dq.back();
                ops += (long long)(nums[l] - nums[idx]) * (next_idx - idx);
            }
            dq.push_back(l);
            
            while (ops > k) {
                int front_idx = dq.front();
                ops -= (long long)(nums[front_idx] - nums[r]);
                if (front_idx == r) {
                    dq.pop_front();
                }
                --r;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};