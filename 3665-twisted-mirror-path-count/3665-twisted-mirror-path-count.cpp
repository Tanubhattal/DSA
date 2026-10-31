class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;
        
        vector<vector<vector<long long>>> memo(m, vector<vector<long long>>(n, vector<long long>(2, -1)));
        
        auto getJump = [&](int r, int c, int dir, auto& self_ref) -> pair<int, int> {
            int nr = r, nc = c;
            while (true) {
                if (dir == 0) nc++;
                else nr++;
                
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) return {-1, -1};
                
                if (grid[nr][nc] == 1) {
                    dir = 1 - dir;
                } else {
                    return {nr, nc};
                }
            }
        };
        
        auto dfs = [&](int r, int c, int dir, auto& self_ref) -> long long {
            if (r == m - 1 && c == n - 1) return 1;
            if (memo[r][c][dir] != -1) return memo[r][c][dir];
            
            long long ways = 0;
            
            pair<int, int> next1 = getJump(r, c, dir, self_ref);
            if (next1.first != -1) {
                ways = (ways + self_ref(next1.first, next1.second, dir, self_ref)) % MOD;
            }
            
            int alt_dir = 1 - dir;
            pair<int, int> next2 = getJump(r, c, alt_dir, self_ref);
            if (next2.first != -1) {
                ways = (ways + self_ref(next2.first, next2.second, alt_dir, self_ref)) % MOD;
            }
            
            return memo[r][c][dir] = ways;
        };
        
        return dfs(0, 0, 0, dfs);
    }
};