class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int itr = numBottles;
        while(itr>=numExchange)
        {
            int res = itr/numExchange;
            int rem = itr%numExchange;
            ans += res;
            itr = res + rem;
        }
        return ans;
        
    }
};