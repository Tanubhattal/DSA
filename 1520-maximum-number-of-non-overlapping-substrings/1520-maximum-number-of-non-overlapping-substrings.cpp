class Solution {
public:
    int check(string &s, int i, vector<int>& left, vector<int>& right) {
        int r = right[s[i] - 'a'];
        for (int j = i; j <= r; ++j) {
            if (left[s[j] - 'a'] < i)
                return -1;
            r = max(r, right[s[j] - 'a']);
        }
        return r;
    }
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> left(26, s.size()), right(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            left[s[i] - 'a'] = min(left[s[i] - 'a'], i);
            right[s[i] - 'a'] = max(right[s[i] - 'a'], i);
        }
        int right_end = -1;
        vector<string> res;
        for (int i = 0; i < s.size(); ++i) {
            if (i == left[s[i] - 'a']) {
                int new_right = check(s, i, left, right);
                if (new_right != -1) {
                    if (i > right_end)
                        res.push_back("");
                    right_end = new_right;
                    res.back() = s.substr(i, right_end - i + 1);
                }
            }
        }
        return res;
    }
};