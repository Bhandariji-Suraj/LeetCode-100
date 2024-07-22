class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();
        
        int rowindex = 0;
        int columnindex = column-1;
        while(rowindex <row && columnindex >=0)
        {
            int value = matrix[rowindex][columnindex];
            if(value == target) return true;
            else if(value < target) rowindex++;
            else columnindex--;
        }
        return false;
        
    }
};