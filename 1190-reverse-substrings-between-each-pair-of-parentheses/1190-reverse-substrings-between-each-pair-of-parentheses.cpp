class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string current;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '(') {
                st.push(current);
                current = "";
            } else if (c == ')') {
                reverse(current.begin(), current.end());
                current = st.top() + current;
                st.pop();
            } else {
                current += c;
            }
        }

        return current;
        
    }
};