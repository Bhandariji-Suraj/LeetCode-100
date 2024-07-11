class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=0;
        while(j<s.size())
        {
            if(isalnum(s[j]))
            {
                s[i++] = tolower(s[j]);
            }
            j++;
        }
        cout<<s<<endl;
        
        int left =0,right = i-1;
        while(left<right)
        {
            if(s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;
    }
};