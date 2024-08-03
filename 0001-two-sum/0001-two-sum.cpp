class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        
        vector<pair<int ,int> >numi;
        for(int i=0;i<nums.size();i++)
        {
            numi.push_back({nums[i],i});
        }
        
        sort(numi.begin(),numi.end());
        
        int s=0,e=nums.size()-1;
        
        while(s<e)
        {
            int sum = numi[s].first + numi[e].first;
            
            if(sum == target)
                return {numi[s].second, numi[e].second};
            else if (sum<target)
                s++;
            else
                e--;
        }
        return {-1,-1};
        
        
        
        // for(int i=0;i<nums.size()-1;i++)
        // {
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         if(nums[i] + nums[j] == target) return {i,j};
        //     }
        // }
        // return {-1,-1};
    }
};