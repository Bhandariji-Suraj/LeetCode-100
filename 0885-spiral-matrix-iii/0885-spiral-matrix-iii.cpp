class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int steps = 1;  
        int r = rStart, c = cStart;
        int dir = 0;
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};
        
        result.push_back({r, c}); 
        
        while (result.size() < rows * cols) {
            for (int i = 0; i < steps; ++i) { 
                r += dr[dir];
                c += dc[dir];
                
                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    result.push_back({r, c});
                }
            }
            
            dir = (dir + 1) % 4; 
            if (dir == 0 || dir == 2) {
                steps++;
            }
        }
        
        return result;
        
    }
};