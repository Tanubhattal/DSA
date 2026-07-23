class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        if (n == 2) return 2;
        int msb = 0;
        for (int i = 30; i >= 0; --i) {
            if ((n >> i) & 1) {
                msb = i;
                break;
            }
        }
        return 1 << (msb + 1);
    }
};