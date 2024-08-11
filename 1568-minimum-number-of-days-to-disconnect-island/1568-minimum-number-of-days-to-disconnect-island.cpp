class Solution {
public:
    bool isConnected(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int islands = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    if (islands > 0) return false;
                    dfs(grid, visited, i, j);
                    islands++;
                }
            }
        }
        
        return islands == 1;
    }
    
    
    
    
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j]) return;
        
        visited[i][j] = true;
        
        dfs(grid, visited, i - 1, j); // Up
        dfs(grid, visited, i + 1, j); // Down
        dfs(grid, visited, i, j - 1); // Left
        dfs(grid, visited, i, j + 1); // Right
    }
    
    
    
    
    
    
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (!isConnected(grid)) return 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (!isConnected(grid)) return 1;
                    grid[i][j] = 1;
                }
            }
        } 
        return 2;  
    }
};