class Solution {
public:
    int findComplement(int num) {
        if(num ==0) return 1;
        if(num == 1) return 0;
        int x = floor(log2(num)) + 1;
        unsigned int mask = (1U << x) - 1;
        return mask ^ num;
        
    }
};