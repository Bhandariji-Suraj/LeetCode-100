class Solution {
public:
    string finalString(string s) {
        string result;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == 'i') {
                int left = 0, right = result.size() - 1;
                while (left < right) {
                    swap(result[left], result[right]);
                    left++;
                    right--;
                }
            } else {
                result += c;
            }
        }
        return result;
        
    }
};