class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int R, int C, int &perimeter) {
        if(r < 0 || c < 0 || r >= R || c >= C || grid[r][c] == 0) {
            perimeter++;
            return;
        }
        if(grid[r][c] == -1) return;

        grid[r][c] = -1;

        int rd[4] = {-1, 0, 1, 0};
        int cd[4] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            dfs(grid, r + rd[i], c + cd[i], R, C, perimeter);
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        int perimeter = 0;

        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, R, C, perimeter);
                    return perimeter;
                }
            }
        }
        return 0;
    }
};