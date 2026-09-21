class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> prev_count(k, 0);    
        for (int num : nums) {
            vector<long long> curr_count(k, 0);
            int current_rem = num % k;
            curr_count[current_rem] += 1;
            for (int r = 0; r < k; ++r) {
                if (prev_count[r] > 0) {
                    int new_r = (r * current_rem) % k;
                    curr_count[new_r] += prev_count[r];
                }
            }
            for (int r = 0; r < k; ++r) {
                result[r] += curr_count[r];
            }
            prev_count = curr_count;
        }
        
        return result;
    }
};