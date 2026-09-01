class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int sx = -1, sy = -1;
        int num_litter = 0;
        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (classroom[i][j] == 'L') {
                    litter_id[i][j] = num_litter++;
                }
            }
        }
        if (num_litter == 0) return 0;
        int target_mask = (1 << num_litter) - 1;
        vector<vector<vector<int>>> bestEnergy(m, vector<vector<int>>(n, vector<int>(1 << num_litter, -1)));
        queue<tuple<int, int, int, int>> q;
        q.push({sx, sy, 0, 0});
        bestEnergy[sx][sy][0] = energy;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto [x, y, mask, steps] = q.front();
            q.pop();
            int e = bestEnergy[x][y][mask];
            if (e <= 0) continue; 
            for (auto& d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && classroom[nx][ny] != 'X') {
                    int ne = e - 1;
                    if (classroom[nx][ny] == 'R') {
                        ne = energy; 
                    }
                    if (ne < 0) continue;
                    int nmask = mask;
                    if (classroom[nx][ny] == 'L') {
                        nmask |= (1 << litter_id[nx][ny]);
                    }
                    if (nmask == target_mask) return steps + 1;
                    if (ne > bestEnergy[nx][ny][nmask]) {
                        bestEnergy[nx][ny][nmask] = ne;
                        q.push({nx, ny, nmask, steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};