class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        int longestSeqSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                longestSeqSum += nums[i];
            } else {
                break;
            }
        }
        
        std::sort(nums.begin(), nums.end());
        int missing = longestSeqSum;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > missing) {
                break;
            }
            if (nums[i] == missing) {
                missing++;
            }
        }
        return missing;
        
    }
};