class Solution {
public:
    void dfs(vector<vector<int>>& graph, int x, int y, int size) {
        if (x < 0 || x >= size || y < 0 || y >= size || graph[x][y] != 0) {
            return;
        }
        
        graph[x][y] = 1;
        
        dfs(graph, x - 1, y, size);
        dfs(graph, x + 1, y, size);
        dfs(graph, x, y - 1, size);
        dfs(graph, x, y + 1, size);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int size = n * 3;
        vector<vector<int>> graph(size, vector<int>(size, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    graph[i * 3][j * 3 + 2] = 1;
                    graph[i * 3 + 1][j * 3 + 1] = 1;
                    graph[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    graph[i * 3][j * 3] = 1;
                    graph[i * 3 + 1][j * 3 + 1] = 1;
                    graph[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
        
        int regions = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (graph[i][j] == 0) {
                    dfs(graph, i, j, size);
                    regions++;
                }
            }
        }
        
        return regions;

        
    }
};