class Solution {

public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        nums.erase(remove(nums.begin(),nums.end(),val),nums.end());
        int count = nums.size();
        
        // if(nums.empty()) return 0;
        // vector<int> ans;
        // int count=0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i] != val)
        //     {
        //         ans.push_back(nums[i]);
        //         count++;
        //     }
        // }
        // nums = ans;
        return count;
        
    }
};