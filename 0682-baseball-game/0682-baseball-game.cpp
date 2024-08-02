class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> list;
        for(int i=0;i<operations.size();i++)
        {
            if(operations[i] == "+")
            {
                int sum = list.back()+ list[list.size()-2];
                list.push_back(sum);
            }
            else if(operations[i] == "D")
            {
                int prod = 2 * list.back();
                list.push_back(prod);
            }
            else if(operations[i] == "C")
            {
                list.pop_back();
            }
            else
            {
                list.push_back(stoi(operations[i]));
            }
        }
        int sum= 0;
        for(int i=0;i<list.size();i++)
        {
            sum += list[i];
        }
        return sum;
        
    }
};