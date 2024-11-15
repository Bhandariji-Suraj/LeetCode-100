class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = 0;

        for (int num : nums) {
            totalOnes += num;
        }

        if (totalOnes == 0 || totalOnes == n) return 0;

        int maxOnesInWindow = 0;
        int currentOnes = 0;

        for (int i = 0; i < totalOnes; i++) {
            currentOnes += nums[i];
        }
        maxOnesInWindow = currentOnes;

        for (int i = totalOnes; i < n + totalOnes; i++) {
            currentOnes += nums[i % n] - nums[(i - totalOnes) % n];
            maxOnesInWindow = max(maxOnesInWindow, currentOnes);
        }

        return totalOnes - maxOnesInWindow;
        
    }
};