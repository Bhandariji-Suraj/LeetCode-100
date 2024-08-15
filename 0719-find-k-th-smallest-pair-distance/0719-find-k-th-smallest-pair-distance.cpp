class Solution {
public:
    
    int countPairs(vector<int>& nums, int mid) {
        int count = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (j < nums.size() && nums[j] - nums[i] <= mid) {
                j++;
            }
            count += j - i - 1;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nums[nums.size() - 1] - nums[0];
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countPairs(nums, mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
        
    }
};