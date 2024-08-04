class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        vector<int> subarraysum;
        for(int i=0;i<n;i++)
        {
            int sum1 = 0;
            for(int j=i;j<n;j++)
            {
                sum1 += nums[j];
                subarraysum.push_back(sum1);  
            }
        }
        sort(subarraysum.begin(), subarraysum.end());
        int sum = 0;
        for(int i = left-1;i<right;i++)
        {
            sum = (sum + subarraysum[i]) % MOD;
        }
        return sum;
        
    }
};