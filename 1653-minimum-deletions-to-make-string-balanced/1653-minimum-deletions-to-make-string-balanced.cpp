class Solution {
public:
    int minimumDeletions(string s) {
        int b_cnt = 0;
        int mindel=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] =='b')
            {
                b_cnt++;
            }
            else
            {
                mindel = min(mindel +1, b_cnt);
            }
        }
        return mindel;
        
    }
};