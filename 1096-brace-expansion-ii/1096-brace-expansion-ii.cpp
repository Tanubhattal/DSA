#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
    int i = 0;
    string s;

    set<string> expr() {
        set<string> res;
        while (true) {
            set<string> t = term();
            res.insert(t.begin(), t.end());
            if (i < s.length() && s[i] == ',') {
                i++;
            } else {
                break;
            }
        }
        return res;
    }

    set<string> term() {
        set<string> res = {""};
        while (i < s.length() && (isalpha(s[i]) || s[i] == '{')) {
            set<string> f = factor();
            set<string> next_res;
            for (const string& a : res) {
                for (const string& b : f) {
                    next_res.insert(a + b);
                }
            }
            res = move(next_res);
        }
        return res;
    }

    set<string> factor() {
        if (s[i] == '{') {
            i++;
            set<string> res = expr();
            i++;
            return res;
        } else {
            string f = "";
            f += s[i];
            i++;
            return {f};
        }
    }

public:
    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;
        set<string> res_set = expr();
        return vector<string>(res_set.begin(), res_set.end());
    }
};