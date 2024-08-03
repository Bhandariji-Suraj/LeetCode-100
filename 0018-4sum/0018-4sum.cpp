class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int a=0;a<n-3;a++)
        {
            if( a > 0 && nums[a] == nums[a - 1]) continue;
            for(int b=a+1;b<n-2;b++)
            {
                if( b > a+1 && nums[b] == nums[b-1]) continue;
                int s =b+1;
                int e = n-1;
                while(s<e)
                {
                    long long sum = static_cast<long long>(nums[a])+nums[b]+nums[s] + nums[e];
                    if(sum == target)
                    {
                        ans.push_back({nums[a], nums[b], nums[s] , nums[e]});
                        while(s<e && nums[s] == nums[s+1]) s++;
                        while(s<e && nums[e] == nums[e-1]) e--;
                        s++;
                        e--;
                    }
                    else if(sum<target) s++;
                    else
                        e--;
                }
            }
        }
        return ans;
        
        
    }
};