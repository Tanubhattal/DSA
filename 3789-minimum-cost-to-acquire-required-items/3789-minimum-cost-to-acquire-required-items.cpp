#include <algorithm>

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        cost1 = std::min(cost1, costBoth);
        cost2 = std::min(cost2, costBoth);
        long long totalCost = 0;
        if (costBoth < cost1 + cost2) {
            long long bothCount = std::min(need1, need2);
            totalCost += bothCount * costBoth;
            need1 -= bothCount;
            need2 -= bothCount;
        }
        if (need1 > 0) {
            totalCost += (long long)need1 * std::min(cost1, costBoth);
        }
        if (need2 > 0) {
            totalCost += (long long)need2 * std::min(cost2, costBoth);
        }
        return totalCost;
    }
};