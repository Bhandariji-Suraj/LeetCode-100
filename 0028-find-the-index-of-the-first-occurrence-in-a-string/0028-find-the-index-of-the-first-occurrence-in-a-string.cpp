class Solution {
public:
    int strStr(string haystack, string needle) {
        int first,second;
        int n = haystack.size(),m = needle.size();
        for(int i =0;i<= n-m;i++)
        {
            first =i;
            second = 0;
            while(second < m)
            {
                if(haystack[first] != needle[second])
                    break;
                else
                {
                    first++;
                    second++;
                }

            }
            if(second == m)
                return first - second;
        }
        return -1;
        
    }
};