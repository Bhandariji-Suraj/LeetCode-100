class Solution {
public:
    int passThePillow(int n, int time) {
        int res = 0;
        if((time/(n-1))%2==0)
        {
            res = (1+time%(n-1));
        }
        else
        {
            res = (n-time%(n-1));
        }
        return res;
        
    }
};