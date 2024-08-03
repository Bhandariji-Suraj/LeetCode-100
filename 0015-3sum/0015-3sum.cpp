class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> >result;
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int s=i+1,e=nums.size()-1;
            
            while(s<e)
            {
                int sum = nums[i]+ nums[s] + nums[e];
                if(sum ==0)
                {
                    result.push_back({nums[i],nums[s], nums[e]});
                    
                    while(s<e && nums[s] == nums[s+1]) s++;
                    while(s<e && nums[e] == nums[e-1]) e--;
                    s++,e--;
                    
                }
                else if(sum<0)
                    s++;
                else
                    e--;
            }
        
            
            
            
            
            // for(int j=i+1;j<nums.size()-1;j++)
            // {
            //     if (j > i+1 && nums[j] == nums[j - 1]) continue;
            //     for(int k =j+1;k<nums.size();k++)
            //     {
            //         if (k > j+1 && nums[k] == nums[k - 1]) continue;
            //         int sum = nums[i]+ nums[j] + nums[k];
            //         if(sum == 0)
            //         {
            //             ans.push_back(nums[i]);
            //             ans.push_back(nums[j]);
            //             ans.push_back(nums[k]);
            //             result.push_back(ans);
            //             ans.clear();
            //         }
            //     }
            // }
        }
        return result;
        
    }
};