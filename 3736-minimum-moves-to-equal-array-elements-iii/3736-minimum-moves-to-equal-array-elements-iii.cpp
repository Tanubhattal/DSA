class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_val = nums[0];
        for(int x : nums) {
            if(x > max_val) max_val = x;
        }
        int total_moves = 0;
        for(int x : nums) {
            total_moves += (max_val - x);
        }
        return total_moves;
    }
};