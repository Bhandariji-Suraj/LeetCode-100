class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min_value = arrays[0][0];
        int max_value = arrays[0][arrays[0].size()-1];
        int max_distance = 0;
        
        for(int i=1;i<arrays.size();i++)
        {
            max_distance = max(max_distance, abs(arrays[i][arrays[i].size()-1] - min_value));
            max_distance = max(max_distance, abs(max_value - arrays[i][0]));
            
            min_value = min(min_value, arrays[i][0]);
            max_value = max(max_value, arrays[i][arrays[i].size()-1]);
        }
        return max_distance;
        
    }
};