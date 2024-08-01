class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x =0;
        string str;
        for(int i=0;i<operations.size();i++)
        {
            str = operations[i];
            if(str == "++X" || str == "X++")
            {
                ++x;
            }
            
            else if(str == "--X" || str == "X--")
            {
                --x;
            }
            
            
        }
        return x;
        
    }
};