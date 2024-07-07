// void reverse(vector<int> & nums, int start, int end)
// {
//     while(start<end)
//     {
//         swap(nums[start], nums[end]);
//         start++;
//         end--;
//     }
// }
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        //m-2
        vector<int> temp(n);
        for(int i=0;i<n;i++)
        {
            temp[(i+k)%n] = nums[i];
        }
        nums = temp;
        
        
        //m-1
        // k = k % n;
        // reverse(nums,0,n-1);
        // reverse(nums,0,k-1);
        // reverse(nums,k,n-1);
        
        
    }
};