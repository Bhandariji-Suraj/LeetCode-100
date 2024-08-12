class Solution {
public:
    
    
    bool check(vector<int> piles, int h, int mid)
    {
        int currenthrs = 0;
        for(int i=0;i<piles.size();i++)
        {
            int pile = piles[i];
            currenthrs += pile/mid;
            int rem = pile%mid;
            if(rem != 0)
                currenthrs++;
            
        }
        if(currenthrs > h)
        {
            return false;
            
        }
        else
            return true;
    }
    
    
    
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int e = piles[piles.size()-1];
        int s=1;
        while(s<e)
        {
            int mid = s+(e-s)/2;
            if(check(piles,h,mid))
            {
                e = mid;
            }
            else
                s = mid+1;
        }
        return s;
        
    }
};