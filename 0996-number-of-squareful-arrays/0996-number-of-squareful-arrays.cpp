class Solution {
public:
    
    bool isSquare(int x)
    {
        int root = (int) sqrt(x);
        return root * root  == x;
    }
    
    
    
    int backtrack(vector<int> &nums, vector<bool> &used, vector<int> current)
    {
        int count =0;
        if(current.size() == nums.size()) 
            return 1;
        for(int i =0;i<nums.size(); i++)
        {
            if(used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1]))
                continue;
            if(!current.empty() && !isSquare(current.back() + nums[i]))
                continue;
            
            used[i] = true;
            current.push_back(nums[i]);
            count += backtrack(nums,used,current);
            current.pop_back();
            used[i] = false;
        }
        
        return count;
    }
    
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used (nums.size(), false);
        return backtrack(nums, used, {} );
    }
};