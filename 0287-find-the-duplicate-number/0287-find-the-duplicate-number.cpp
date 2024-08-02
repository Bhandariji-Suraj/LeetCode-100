class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int e=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=1;i<e;i++)
        {
            if(nums[i] == nums[i-1])
            {
                return nums[i-1];
            }
        }
        return -1;
        
    }
};