class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rowMins(m);
        vector<int> colMaxs(n, INT_MIN);

        for (int i = 0; i < m; i++) {
            int minVal = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < minVal) {
                    minVal = matrix[i][j];
                }
            }
            rowMins[i] = minVal;
        }

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (matrix[i][j] > colMaxs[j]) {
                    colMaxs[j] = matrix[i][j];
                }
            }
        }
        
        vector<int> luckyNumbers;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == rowMins[i] && matrix[i][j] == colMaxs[j]) {
                    luckyNumbers.push_back(matrix[i][j]);
                }
            }
        }

        return luckyNumbers;
        
        
    }
};