class Solution {
public:
    
    string add(string num1, string num2)
    {
        int id1 = num1.size()-1;
        int id2 = num2.size()-1;
        int carry=0,sum=0;
        string ans;
        while(id2 >= 0)
        {
            sum = (num1[id1]- '0') + (num2[id2] - '0') + carry;
            carry = sum/10;
            char c = '0'+sum%10;
            ans += c;
            id1--;
            id2--;
        }
        while(id1>=0)
        {
            sum = (num1[id1] - '0')+ carry;
            carry = sum/10;
            char c = '0'+sum%10;
            ans += c;
            id1--;
        }
        if(carry)
        {
            ans += '1';
        }
        int s =0, e = ans.size()-1;
        while(s<=e)
        {
            swap(ans[s], ans[e]);
            s++;
            e--;
        }
        return ans;
    }
    
    string addStrings(string num1, string num2) {
        
        if(num1.size() < num2.size())
            return add(num2, num1);
        else
            return add(num1, num2);
        
    }
};