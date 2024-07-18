class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> result(26,0);
        for(int i =0;i<sentence.size();i++)
        {
            result[sentence[i]- 'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(result[i] == 0)
            {
                return false;
            }
        }
        return true;
        
    }
};