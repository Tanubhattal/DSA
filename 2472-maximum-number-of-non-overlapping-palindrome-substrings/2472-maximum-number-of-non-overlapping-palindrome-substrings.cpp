class Solution {
public:
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; 
            r--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i <= n - k; i++) {
            if (isPalindrome(s, i, i + k - 1)) {
                ans++;
                i += k - 1; 
            } 
            else if (i + k < n && isPalindrome(s, i, i + k)) {
                ans++;
                i += k; 
            }
        }
        
        return ans;
    }
};