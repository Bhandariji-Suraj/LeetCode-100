class Solution {
public:
    
    
    int gcd(int a, int b)
    {
        return b==0 ? a : gcd(b, a%b);
    }
    
    
    string fractionAddition(string expression) {
        int result_numerator =0, result_denominator = 1;
        
        for (int i = 0, n = expression.size(); i < n;) {
            int sign = 1;
            if (expression[i] == '-' || expression[i] == '+') {
                sign = expression[i] == '-' ? -1 : 1;
                ++i;
            }
            
            int numerator = 0;
            while (i < n && isdigit(expression[i])) {
                numerator = numerator * 10 + (expression[i] - '0');
                ++i;
            }
            
            ++i;
            
            int denominator = 0;
            while (i < n && isdigit(expression[i])) {
                denominator = denominator * 10 + (expression[i] - '0');
                ++i;
            }
            
            result_numerator = result_numerator * denominator + sign * numerator * result_denominator;
            result_denominator *= denominator;
            
            int gcd_result = gcd(abs(result_numerator), result_denominator);
            result_numerator /= gcd_result;
            result_denominator /= gcd_result;
        }
        
        return to_string(result_numerator) + "/" + to_string(result_denominator);
        
        
    }
};