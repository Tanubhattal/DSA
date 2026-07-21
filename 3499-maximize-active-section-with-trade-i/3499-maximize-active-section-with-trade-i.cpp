class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int originalOnes = 0;

        for (char c : s) {
            if (c == '1') {
                originalOnes++;
            }
        }

        string t = "1" + s + "1";
        int n = t.size();

        vector<int> leftZero(n, 0), rightZero(n, 0);

        // Length of zero block ending at i
        for (int i = 1; i < n; i++) {
            if (t[i] == '0') {
                leftZero[i] = leftZero[i - 1] + 1;
            }
        }

        // Length of zero block starting at i
        for (int i = n - 2; i >= 0; i--) {
            if (t[i] == '0') {
                rightZero[i] = rightZero[i + 1] + 1;
            }
        }

        int ans = originalOnes;

        int i = 0;

        while (i < n) {
            if (t[i] == '1') {
                int j = i;

                while (j < n && t[j] == '1') {
                    j++;
                }

                // Check whether the block of 1s is surrounded by 0s
                if (i > 0 && j < n &&
                    t[i - 1] == '0' &&
                    t[j] == '0') {

                    int onesLen = j - i;

                    int leftZeros = leftZero[i - 1];
                    int rightZeros = rightZero[j];

                    int newActive =
                        originalOnes - onesLen +
                        leftZeros + onesLen + rightZeros;

                    ans = max(ans, newActive);
                }

                i = j;
            } else {
                i++;
            }
        }

        return ans;
    }
};