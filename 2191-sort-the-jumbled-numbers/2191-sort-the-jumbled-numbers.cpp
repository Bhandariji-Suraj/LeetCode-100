class Solution {
public:
    int mapNumber(int num, const vector<int>& mapping) 
    {
        string numStr = to_string(num);
        string mappedStr = "";
        for (int i = 0; i < numStr.size(); ++i) 
        {
            int digit = numStr[i] - '0';
            mappedStr += to_string(mapping[digit]);
        }
        return stoi(mappedStr);
    }
    
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) 
    {
        vector<pair<int, int>> mappedNums;
        for (int i = 0; i < nums.size(); ++i) 
        {
            int mappedValue = mapNumber(nums[i], mapping);
            mappedNums.push_back(make_pair(mappedValue, nums[i]));
        }
        
        stable_sort(mappedNums.begin(), mappedNums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });
        
        vector<int> sortedNums;
        for (int i = 0; i < mappedNums.size(); ++i) 
        {
            sortedNums.push_back(mappedNums[i].second);
        }
        
        return sortedNums;
        
    }
};