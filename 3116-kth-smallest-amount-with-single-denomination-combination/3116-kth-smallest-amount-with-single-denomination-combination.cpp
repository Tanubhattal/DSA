class Solution {
public:
    long long gcd(long long a, long long b) {
        return std::gcd(a, b);
    }
    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }
    long long countMultiples(long long target, const std::vector<int>& coins) {
        int n = coins.size();
        long long total = 0;
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long currentLcm = 1;
            int subsetSize = 0;
            bool overflow = false;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    subsetSize++;
                    currentLcm = lcm(currentLcm, coins[i]);
                    if (currentLcm > target) {
                        overflow = true;
                        break;
                    }
                }
            }
            if (overflow) continue;
            if (subsetSize % 2 == 1) {
                total += target / currentLcm;
            } else {
                total -= target / currentLcm;
            }
        }
        return total;
    }
    long long findKthSmallest(std::vector<int>& coins, int k) {
        long long minCoin = *std::min_element(coins.begin(), coins.end());
        long long low = 1;
        long long high = minCoin * (long long)k;
        long long ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countMultiples(mid, coins) >= k) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};