class Solution {
public:
    
    
    void solve(vector<int>& nums,vector<int> output,int idx,vector<vector<int> >& ans )
    {
        //base condition
        if(idx>= nums.size())
        {
            ans.push_back(output);
            return;
        }
        
        //exclude
        solve(nums,output,idx+1,ans);
        
        //include
        int element = nums[idx];
        output.push_back(element);
        solve(nums,output,idx+1,ans);
    }
    
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> output;
        int idx = 0;
        solve(nums,output,idx,ans);
        return ans;
    }
};