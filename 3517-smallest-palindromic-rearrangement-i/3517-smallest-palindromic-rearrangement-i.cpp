class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int half_len = n / 2;
        string half = s.substr(0, half_len);
        sort(half.begin(), half.end());
        string result = half;
        if (n % 2 != 0) {
            result += s[half_len]; 
        }
        string right_half = half;
        reverse(right_half.begin(), right_half.end());
        result += right_half;
        return result;
    }
};