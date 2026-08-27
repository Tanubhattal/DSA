class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        string res = "";
        int n = s.length();
        auto dfs = [&](auto& self, int i, bool is_greater) -> bool {
            if (i == n) {
                return is_greater;
            }
            if (is_greater) {
                for (int k = 0; k < 26; ++k) {
                    if (count[k] > 0) {
                        count[k]--;
                        res += (char)('a' + k);
                        self(self, i + 1, true);
                        return true; 
                    }
                }
            } else {
                int req = target[i] - 'a';
                if (count[req] > 0) {
                    count[req]--;
                    res += target[i];
                    if (self(self, i + 1, false)) return true;
                    res.pop_back();
                    count[req]++;
                }
                for (int k = req + 1; k < 26; ++k) {
                    if (count[k] > 0) {
                        count[k]--;
                        res += (char)('a' + k);
                        self(self, i + 1, true); 
                        return true;
                    }
                }
            }
            return false;
        };
        if (dfs(dfs, 0, false)) {
            return res;
        }
        return "";
    }
};