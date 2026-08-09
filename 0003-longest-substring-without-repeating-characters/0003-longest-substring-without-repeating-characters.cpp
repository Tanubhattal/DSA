class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>seen;
        int left = 0;
        int ans = 0;
        for (int right = 0; right < s.length(); right++){
            while(seen.count(s[right])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            ans = max(ans, right-left+1);
        }
        return ans;
        
    }
};