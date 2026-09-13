class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) ones1.push_back({i, j});
                if (img2[i][j] == 1) ones2.push_back({i, j});
            }
        }
        int max_overlap = 0;
        unordered_map<int, int> shift_count;
        for (auto& p1 : ones1) {
            for (auto& p2 : ones2) {
                int shift = (p1.first - p2.first) * 100 + (p1.second - p2.second);
                shift_count[shift]++;
                max_overlap = max(max_overlap, shift_count[shift]);
            }
        }
        return max_overlap;
    }
};