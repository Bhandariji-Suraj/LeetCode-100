class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest = nums[0];
        
        for(int i=0;i<nums.size();i++)
        {
            int num = nums[i];
            if(abs(num)< abs(closest) || abs(num) == abs(closest) && num > closest)
            {
                closest = num;
            }
        }
        return closest;
        
    }
};