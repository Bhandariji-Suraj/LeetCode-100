class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()> k)
        {
            string news = "";
            for(int i =0 ; i < s.size(); i += k)
            {
                int sum =0;
                for(int j=i;j<i+k && j<s.size();j++)
                {
                    sum += s[j] - '0';
                }
                news += to_string(sum);
            }
            s = news;
        }
        return s;
        
    }
};