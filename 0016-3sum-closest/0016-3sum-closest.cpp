class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int close = nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-2;i++)
        {
            int s= i+1;
            int e = nums.size()-1;
            while(s<e)
            {
                int sum = nums[i]+ nums[s]+nums[e];
                if(sum == target) 
                    return sum;
                long long sumdiff = static_cast<long long>(abs(sum-target));
                long long closediff = abs(static_cast<long long>(close - target));
                if(sumdiff < closediff)
                    close = sum;
                if(sum < target)
                    s++;
                else
                    e--;
            }
            
            
        }
        return close;
        
    }
};