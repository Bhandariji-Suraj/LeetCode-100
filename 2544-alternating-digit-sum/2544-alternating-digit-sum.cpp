class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> arr;
        while(n>0)
        {
            arr.push_back(n%10);
            n = n/10;
        }
        int s=0,e=arr.size()-1;
        while(s<e)
        {
            swap(arr[s++], arr[e--]);
        }
        
        
        int sum = 0;
        for(int i=0;i<arr.size();i++)
        {
            if(i%2==0)
            {
                sum += arr[i];
            }
            else
            {
                sum -= arr[i];
            }
        }
        return sum;
    }
};