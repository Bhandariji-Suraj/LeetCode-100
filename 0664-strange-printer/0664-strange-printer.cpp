class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int length = 1; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            dp[i][j] = length; 
            for (int k = i; k < j; k++) {
                if (s[k] == s[j]) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] - 1);
                } else {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
    }
    
    return dp[0][n-1];
        
    }
};