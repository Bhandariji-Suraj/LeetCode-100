class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        
        int sum1 =0;
        int sum2 =0;
        vector<int> arr;
        
        //ELEMENT SUM
        for(int i=0;i<nums.size();i++)
        {
            sum1 += nums[i];
        }
        
        //digit sum
        //creating an array to store all digits
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]>0)
            {
                arr.push_back(nums[i]%10);
                nums[i] = nums[i]/10;
            }
        }
        //calculating sum
        for(int i=0;i<arr.size();i++)
        {
            sum2 += arr[i]; 
        }
        
        //absolute sum
        sum1 -= sum2;
        return abs(sum1);
        
    }
};