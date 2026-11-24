class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = 1;

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            int g = 0;
            long long l = 1;

            for (int j = i; j < n; ++j) {
                int x = nums[j];
                if (prod > 1000000000000000000LL / x) {
                    break;
                }
                prod *= x;
                g = (g == 0) ? x : std::gcd(g, x);
                l = l * (x / std::gcd((int)l, x));

                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};