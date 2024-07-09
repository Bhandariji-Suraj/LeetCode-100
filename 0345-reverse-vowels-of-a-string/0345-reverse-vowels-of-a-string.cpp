bool isVowel(char ch)
{
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

class Solution {
public:
    string reverseVowels(string s) {
        int st = 0, e= s.size();
        
        while(st<e)
        {
            while(st<e && !isVowel(s[st]))
            {
                st++;
            }
            while(st<e && !isVowel(s[e]))
            {
                e--;
            }
            if(st<e)
            {
                swap(s[st],s[e]);
                st++;
                e--;
            }
        }
        return s;
        
        
    }
};