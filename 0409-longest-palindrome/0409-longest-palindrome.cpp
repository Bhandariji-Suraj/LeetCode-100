class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> lower(26,0);
        vector<int> upper(26.0);
        for(int i =0;i< s.size();i++)
        {
            if(s[i]>= 'a')
            {
                lower[s[i] - 'a']++;
            }
            else
            {
                upper[s[i]- 'A']++;
            }
        }
        bool odd =0;
        int res =0;
        for(int i =0;i<26;i++)
        {
            if(lower[i]%2 == 0)
            {
                res += lower[i];
            }
            else
            {
                res += lower[i]-1;
                odd =1;
            }
            if(upper[i]%2 ==0)
            {
                res += upper[i];
            }
            else
            {
                res += upper[i]-1;
                odd = 1;
            }
        }
        res += odd;
        return res;
        
    }
};