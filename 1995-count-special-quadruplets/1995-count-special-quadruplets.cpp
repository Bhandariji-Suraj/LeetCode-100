class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<pair<int, int>>> sumMap;
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                sumMap[nums[i] + nums[j]].push_back({i, j});
            }
        }
        
        for (int c = 0; c < n; ++c) {
            for (int d = c + 1; d < n; ++d) {
                int target = nums[d] - nums[c];
                
                if (sumMap.find(target) != sumMap.end()) {
                    for (auto& pair : sumMap[target]) {
                        int a = pair.first;
                        int b = pair.second;
                        
                        if (a < b && b < c) {
                            count++;
                        }
                    }
                }
            }
        }
        
        return count;
        
    }
};