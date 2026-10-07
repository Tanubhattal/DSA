class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        if (s.empty()) return {""};
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        bool found = false;
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                string curr = q.front();
                q.pop();
                if (isValid(curr)) {
                    result.push_back(curr);
                    found = true;
                }
                if (found) continue;
                for (int j = 0; j < curr.length(); ++j) {
                    if (curr[j] != '(' && curr[j] != ')') continue;

                    string nextStr = curr.substr(0, j) + curr.substr(j + 1);
                    if (visited.find(nextStr) == visited.end()) {
                        visited.insert(nextStr);
                        q.push(nextStr);
                    }
                }
            }
            if (found) break;
        }
        return result;
    }
private:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }
};