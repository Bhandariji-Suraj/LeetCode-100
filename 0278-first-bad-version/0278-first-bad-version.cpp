// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s=0,e=n;
        while(s<e)
        {
            int mid = s+(e-s)/2;
            int ans = isBadVersion(mid);
            if(ans == true)
            {
                e=mid;
            }
            else
                s = mid+1;
        }
        return e;
        
    }
};