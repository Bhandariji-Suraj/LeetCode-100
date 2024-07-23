class Solution {
public:
    int minimumSum(int num) {
        int minSum = INT_MAX;
        vector<int> digits;
        while(num>0)
        {
            digits.push_back(num%10);
            num = num/10;
        }
        sort(digits.begin(), digits.end());
        do {
            int num1 = digits[0] * 10 + digits[1];
            int num2 = digits[2] * 10 + digits[3];
            minSum = std::min(minSum, num1 + num2);

            num1 = digits[0] * 10 + digits[2];
            num2 = digits[1] * 10 + digits[3];
            minSum = std::min(minSum, num1 + num2);

            num1 = digits[0] * 10 + digits[3];
            num2 = digits[1] * 10 + digits[2];
            minSum = std::min(minSum, num1 + num2);

            num1 = digits[1] * 10 + digits[2];
            num2 = digits[0] * 10 + digits[3];
            minSum = std::min(minSum, num1 + num2);

            num1 = digits[1] * 10 + digits[3];
            num2 = digits[0] * 10 + digits[2];
            minSum = std::min(minSum, num1 + num2);

            num1 = digits[2] * 10 + digits[3];
            num2 = digits[0] * 10 + digits[1];
            minSum = std::min(minSum, num1 + num2);

        } while (std::next_permutation(digits.begin(), digits.end()));
        return minSum;
    }
};