class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        int oddCount = 0;
        string mid = "";
        vector<int> half_count(26, 0);
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                oddCount++;
                mid += (char)('a' + i);
            }
            half_count[i] = count[i] / 2;
        }
        if (oddCount > 1) {
            return "";
        }
        int n = s.length();
        int m = n / 2;
        string half = "";
        for (int i = 0; i < m; i++) {
            bool found = false;
            for (int c = 0; c < 26; c++) {
                if (half_count[c] > 0) {
                    half_count[c]--; 
                    string largest_half = half + (char)('a' + c);
                    for (int k = 25; k >= 0; k--) {
                        largest_half.append(half_count[k], 'a' + k);
                    }
                    string max_pal = largest_half + mid;
                    string rev_half = largest_half;
                    reverse(rev_half.begin(), rev_half.end());
                    max_pal += rev_half;
                    if (max_pal > target) {
                        half += (char)('a' + c);
                        found = true;
                        break; 
                    } else {
                        half_count[c]++;
                    }
                }
            }
            if (!found) {
                return "";
            }
        }
        string result = half + mid;
        string rev_half = half;
        reverse(rev_half.begin(), rev_half.end());
        result += rev_half;
        if (result <= target) {
            return "";
        }

        return result;
    }
};