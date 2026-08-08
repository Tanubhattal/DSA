#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            if (dp[i + 1] < m && word1[i] == word2[m - dp[i + 1] - 1]) {
                dp[i] = dp[i + 1] + 1;
            } else {
                dp[i] = dp[i + 1];
            }
        }
        vector<int> ans;
        int word2_idx = 0;
        bool used_change = false;
        for (int i = 0; i < n && word2_idx < m; ++i) {
            bool matches = (word1[i] == word2[word2_idx]);
            if (matches) {
                ans.push_back(i);
                word2_idx++;
            } else if (!used_change) {
                int remaining_needed = m - word2_idx - 1;
                if (dp[i + 1] >= remaining_needed) {
                    ans.push_back(i);
                    word2_idx++;
                    used_change = true;
                }
            }
        }
        return (ans.size() == m) ? ans : vector<int>();
    }
};