class Solution {
public:
    int findMin(vector<int>& nums) {
        //two liner code
        // sort(nums.begin(),nums.end());
        // return nums[0];
        
        //legal approach
        int s=0,e=nums.size()-1;
        while(s<e)
        {
            int mid = s+(e-s)/2;
            if(nums[mid]>nums[e])
            {
                s = mid+1;
            }
            else
            {
                e = mid;
            }
        }
        return nums[s];
        
    }
};