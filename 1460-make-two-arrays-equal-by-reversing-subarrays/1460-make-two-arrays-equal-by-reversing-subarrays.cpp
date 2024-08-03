class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(arr.begin(),arr.end());
        sort(target.begin(), target.end());
        if(arr.size() == target.size())
        {
            if(arr.size() == 1)
            {
                if(arr[0] == target[0])
                    return true;
                else 
                    return false;
            }
            for(int i=0;i<arr.size();i++)
            {
                if(arr[i] != target [i])
                {
                    return false;
                }
            }
        }
        else
            return false;
        return true;
        
        
    }
};