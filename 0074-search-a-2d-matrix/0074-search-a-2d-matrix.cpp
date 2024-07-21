class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int row = matrix.size();
        int column = matrix[0].size();
        int s =0, e = row * column - 1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            int midvalue = matrix[mid/column][mid%column];
            if(midvalue == target)
                return true;
            else if (midvalue < target)
                s = mid+1;
            else
                e = mid-1;
            
        }
        return false;
    }
};