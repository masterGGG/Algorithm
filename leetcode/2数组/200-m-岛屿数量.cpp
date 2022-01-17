/*
1. 遍历grid，遇到数字1 岛屿数量+1
2. 将1周围的1染色成2，重复步骤1
*/
class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rowN = grid.size();
        int colN = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < rowN && grid[r+1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < colN && grid[r][c+1] == '1') dfs(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int rowN = grid.size();
        if (!rowN) return 0;
        int colN = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < rowN; ++r) {
            for (int c = 0; c < colN; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }

        return num_islands;
    }
};