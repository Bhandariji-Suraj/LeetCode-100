class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> count(n+1, false);
        for(int i = 0;i<n;i++)
        {
            if(nums[i]>0 && nums[i]<=n)
            {
                count[nums[i]] = true;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(!count[i])
            {
                return i;
            }
        }
        return n+1;
        
    }
};