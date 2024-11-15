class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        int current;
        int prev1 = 1;
        int prev2 = 1;
        for(int i=2;i<=n;i++)
        {
            current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
        }
        return current;
        
    }
};