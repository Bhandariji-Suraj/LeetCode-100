class Solution {
private:
    bool checkEqual(int a[26],int b[26])
    {
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {
                return false;
            }
            
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int count1[26] = {0};
        
        //keeping record of count of characters 
        for(int i =0;i<s1.length();i++)
        {
            int index = s1[i] - 'a';
            count1[index]++;
        }
        
        
        //traversing s2 string with window size equal to size of s1 string and compare
        int i =0;
        int windowSize = s1.length();
        int count2[26] = {0};
        while(i<windowSize && i<s2.length())
        {
            int index = s2[i]-'a';
            count2[index]++;
            i++;
        }
        
        if(checkEqual(count1, count2))
        {
            return true;
        }
        while(i<s2.length())
        {
            char newchar = s2[i];
            int index = newchar -'a';
            count2[index]++;
            char old = s2[i-windowSize];
            index = old-'a';
            count2[index]--;
            i++;
            if(checkEqual(count1, count2)) return true;

        }
        return false;
        
        
        
    }
};