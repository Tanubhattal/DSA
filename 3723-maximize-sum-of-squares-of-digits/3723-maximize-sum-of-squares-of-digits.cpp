class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if ((long long)num * 9 < sum || sum < 0) {
            return "";
        }
        std::string result = "";
        long long current_sum = sum;
        for (int i = 0; i < num; ++i) {
            int remaining_slots = num - 1 - i;
            long long min_needed_for_others = std::max(0LL, current_sum - (long long)remaining_slots * 9);
            long long digit = std::min(9LL, current_sum);
            digit = std::max(digit, min_needed_for_others);
            result += std::to_string(digit);
            current_sum -= digit;
        }
        return result;
    }
};