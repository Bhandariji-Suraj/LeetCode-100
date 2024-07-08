class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;
        while(i<nums.size())
        {
            nums[i] = nums[i]*nums[i];
            i++;
        }
        // for(int i=0;i<nums.size();i++)
        // {
        //     nums[i] = nums[i] * nums[i];
        // }
        sort(nums.begin(), nums.end());
        return nums;
        
    }
};