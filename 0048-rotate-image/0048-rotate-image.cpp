class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int> > result(n,vector<int> (n,0));
        for(int i=0;i<n;i++)
        {
            int row = i;
            for(int j= 0;j<n;j++)
            {
                result[j][n-1-i] = matrix[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            int row = i;
            for(int j= 0;j<n;j++)
            {
                matrix[i][j] = result[i][j];
            }
        }
        
    }
};