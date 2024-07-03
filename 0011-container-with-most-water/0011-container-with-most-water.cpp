class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0,e=height.size()-1;
        long long ans = 0;
        int n = e;
        while(s<e)
        {
            int h =  min(height[s],height[e]);
            long long area = (e-s) *h;
            ans = max(ans,area);
            if(height[s]<height[e])
            {
                s++;
            }
            else
            {
                e--;
            }

        }
        return ans;
    }
};