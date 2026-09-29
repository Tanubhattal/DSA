class Solution {
    int memo[105][105][205]; 
    int m, n;
    bool dfs(int r, int c, int balance, vector<vector<char>>& grid) {
        if (r >= m || c >= n) return false;
        if (grid[r][c] == '(') {
            balance++;
        } else {
            balance--;
        }
        if (balance < 0) return false;
        if (r == m - 1 && c == n - 1) {
            return balance == 0;
        }
        if (memo[r][c][balance] != -1) {
            return memo[r][c][balance];
        }
        bool goRight = dfs(r, c + 1, balance, grid);
        bool goDown = dfs(r + 1, c, balance, grid);
        return memo[r][c][balance] = (goRight || goDown);
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if ((m + n - 1) % 2 != 0) {
            return false;
        }
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }
        memset(memo, -1, sizeof(memo));
        return dfs(0, 0, 0, grid);
    }
};