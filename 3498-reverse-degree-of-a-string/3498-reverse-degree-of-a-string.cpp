class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        for (int i = 0 ; i < s.length(); i++) {
            int reversed = 'z' - s[i] + 1; 
            int currentIndex = i + 1;
            total += (reversed * currentIndex); 
        }
        return total; 
    }
};