class Solution {
public:
    
    
    
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0) {
            return true;
        }
        
        if (grid1[i][j] == 0) {
            return false;
        }

        grid2[i][j] = 0;
        
        bool up = dfs(grid1, grid2, i - 1, j, m, n);
        bool down = dfs(grid1, grid2, i + 1, j, m, n);
        bool left = dfs(grid1, grid2, i, j - 1, m, n);
        bool right = dfs(grid1, grid2, i, j + 1, m, n);
        
        return up && down && left && right;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid2[0].size();
        int subIslandCount = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    if (dfs(grid1, grid2, i, j, m, n)) {
                        subIslandCount++;
                    }
                }
            }
        }

        return subIslandCount;
        
        
    }
};