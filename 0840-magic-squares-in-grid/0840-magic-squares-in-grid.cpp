class Solution {
public:
    
    
    
    bool isMagicSquare(vector<vector<int>>& grid, int r, int c) {
    set<int> nums;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            nums.insert(grid[r + i][c + j]);
        }
    }
    if (nums != set<int>({1, 2, 3, 4, 5, 6, 7, 8, 9})) {
        return false;
    }

    int sum1 = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];
    int sum2 = grid[r + 1][c] + grid[r + 1][c + 1] + grid[r + 1][c + 2];
    int sum3 = grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2];
    int sum4 = grid[r][c] + grid[r + 1][c] + grid[r + 2][c];
    int sum5 = grid[r][c + 1] + grid[r + 1][c + 1] + grid[r + 2][c + 1];
    int sum6 = grid[r][c + 2] + grid[r + 1][c + 2] + grid[r + 2][c + 2];
    int sum7 = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
    int sum8 = grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c];

    return sum1 == sum2 && sum2 == sum3 && sum3 == sum4 && sum4 == sum5 && sum5 == sum6 && sum6 == sum7 && sum7 == sum8 && sum8 == 15;
}
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    for (int r = 0; r < rows - 2; ++r) {
        for (int c = 0; c < cols - 2; ++c) {
            if (isMagicSquare(grid, r, c)) {
                count++;
            }
        }
    }

    return count;
        
    }
};