class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> temp;
        int s =0,mid = 1;
        int count = 1;
        temp.push_back(nums[0]);
        for(int i =1;i<nums.size();i++)
        {
            if(nums[s] == nums[mid])
            {
                mid++;
            }
            else
            {
                temp.push_back(nums[mid]);
                s = mid;
                mid++;
                count++;
            }
        }
        nums = temp;
        return count;
        
    }
};