bool mycomp(pair<int,int>a, pair<int,int> b)
{
    if(a.second < b.second)
        return true;
    else if(a.second > b.second)
        return false;
    else
        return a.first >= b.first;
}
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int,int> >vp;
        for(auto it : mp)
        {
            vp.push_back({it.first, it.second});
        }
        sort(vp.begin(),vp.end(), mycomp);
        
        vector<int> ans;
        for(auto it: vp)
        {
            int x = it.first;
            int y = it.second;
            while(y--)
                ans.push_back(x);
            
        }
        return ans;
        
    }
};