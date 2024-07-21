class Solution {
public:
    
    void lpsfind(vector<int>&lps, string s) {
	    int pre =0, suff =1;
         while(suff < s.size())
	    {
	        if(s[pre] == s[suff])
	        {
	            lps[suff] = pre+1;
	            pre++;
	            suff++;
	        }
	        else
	        {
	            if(pre == 0)
	            {
	                lps[suff] = 0;
	                suff++;
	            }
	            else
	            {
	                pre = lps[pre -1];
	            }
	        }
	    }
	}
    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size(),0);
        lpsfind(lps,needle);
        int first =0,second=0;
        while(second < needle.size() && first < haystack.size())
        {
            if(needle[second] == haystack[first])
            {
                second++;
                first++;
            }
            else
            {
                if(second == 0)
                {
                    first++;
                }
                else
                {
                    second = lps[second-1];
                }
            }
        }
        if(second == needle.size())
            return first-second;
        return -1;
    }
};