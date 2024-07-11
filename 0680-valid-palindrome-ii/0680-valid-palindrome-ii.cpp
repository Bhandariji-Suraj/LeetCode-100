 bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j=0;
        while(j<s.size())
        {
            if(isalnum(s[j]))
            {
                s[i++] = tolower(s[j]);
            }
            j++;
        }
        
        int left=0,right=i-1;
        int count =0;
        while(left<right)
        {
            if(s[left] != s[right])
            {
                return isPalindrome(s,left+1,right) || isPalindrome(s,left,right-1);
            }
            left++;
            right--;
        }
        return true;
        
    }
};