class Solution {
public:
    
    int solve(int left, int right , vector<int>& cuts, vector<vector<int>> &dp)
    {
        if(left>right) return 0;
        
        if(dp[left][right]!=-1)
            return dp[left][right];
        
        int ans = INT_MAX;
        
        for (int k = left; k <= right; ++k) 
        {
            int cost = cuts[right + 1] - cuts[left - 1] + solve(left, k - 1, cuts, dp) + solve(k + 1, right, cuts, dp);
            ans = min(ans, cost);
        }
        return dp[left][right]= (ans == INT_MAX) ? 0 : ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        int m = cuts.size();
        cuts.insert(cuts.begin(), 0);  
        cuts.push_back(n);
        
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
        sort(cuts.begin(), cuts.end());

        return solve(1, m, cuts, dp); 
        
        
        
    }
};