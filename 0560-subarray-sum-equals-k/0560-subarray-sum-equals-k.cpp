class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count =0;
        int s=0,e=nums.size();
        for(int i=0;i<e;i++)
        {int sum =0;
            for(int j=i;j<e;j++)
            {
                sum += nums[j];
                if(sum ==k)
                {
                    count++;
                }
            }
        }
        return count;
        
        
    }
};