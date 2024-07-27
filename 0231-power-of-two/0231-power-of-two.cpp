class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if(n<1) return false;
        while(n%2==0)
        {
            n=n/2;
        }
        return n==1;
        // if (n <= 0) return false; // Exclude negative numbers and zero
        // return (n & (n - 1)) == 0;    
    }

};