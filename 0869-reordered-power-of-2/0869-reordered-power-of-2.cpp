class Solution {
public:
    
    
    
    
    vector<int> countdigits(int num)
    {
        vector<int> count(10,0);
        while(num!=0)
        {
            count[num%10]++;
            num = num/10;
        }
        return count;
    }
    bool reorderedPowerOf2(int n) {
    
        vector<int> ncount = countdigits(n);
        
        for(int i=0;i<31;i++)
        {
            if(ncount == countdigits(1 << i))
                return true;
        }
        return false;
        
    }
};