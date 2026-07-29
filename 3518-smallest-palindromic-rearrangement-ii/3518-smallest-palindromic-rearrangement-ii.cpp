class Solution {
public:
    long long CappedCombination(int n, int r, long long limit) {
        r = min(r, n - r);
        long long result = 1;

        for (int i = 1; i <= r; i++) {
            __int128 temp = (__int128)result * (n - r + i);
            temp /= i;

            if (temp >= limit) {
                return limit;
            }

            result = (long long)temp;
        }

        return result;
    }

    long long countWays(vector<int>& freq, int total, long long limit) {
        long long ways = 1;
        int remaining = total;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                long long current = CappedCombination(
                    remaining,
                    freq[i],
                    limit
                );

                __int128 temp = (__int128)ways * current;

                if (temp >= limit) {
                    return limit;
                }

                ways = (long long)temp;
                remaining -= freq[i];
            }
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string half;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                middle = char('a' + i);
            }

            for (int j = 0; j < freq[i] / 2; j++) {
                half += char('a' + i);
            }
        }

        vector<int> halfFreq(26, 0);

        for (char c : half) {
            halfFreq[c - 'a']++;
        }

        int n = half.size();

        long long totalWays = countWays(halfFreq, n, k);

        if (totalWays < k) {
            return "";
        }

        string firstHalf;

        for (int pos = 0; pos < n; pos++) {
            for (int c = 0; c < 26; c++) {
                if (halfFreq[c] == 0) {
                    continue;
                }

                halfFreq[c]--;

                long long ways = countWays(
                    halfFreq,
                    n - pos - 1,
                    k
                );

                if (k > ways) {
                    k -= ways;
                    halfFreq[c]++;
                } else {
                    firstHalf += char('a' + c);
                    break;
                }
            }
        }

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        if (middle != 0) {
            return firstHalf + middle + secondHalf;
        }

        return firstHalf + secondHalf;
    }
};