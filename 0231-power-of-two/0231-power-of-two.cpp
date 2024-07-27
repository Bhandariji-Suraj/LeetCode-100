class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if (n <= 0) return false; // Exclude negative numbers and zero
        return (n & (n - 1)) == 0;    }

};