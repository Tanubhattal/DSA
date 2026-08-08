class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (int num : s){
            if (s.find(num-1) == s.end()){
                int count = 1;
                int x = num;
                while (s.find(x+1) != s.end()){
                    x++;
                    count++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
        
    }
};