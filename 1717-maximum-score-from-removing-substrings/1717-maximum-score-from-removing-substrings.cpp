class Solution {
private:
        int removeSubstrings(string &s, char first, char second, int points) 
        {
            int score = 0;
            int writePos = 0;

            for (char c : s) 
            {
                if (writePos > 0 && s[writePos - 1] == first && c == second) 
                {
                    --writePos;
                    score += points;
                } 
                else 
                {
                    s[writePos++] = c;
                }
            }

            s.resize(writePos);
            return score;
        }
public:
        int maximumGain(string s, int x, int y) 
        {
            if (x < y) 
            {
                swap(x, y);
                reverse(s.begin(), s.end());
            }

            int score = 0;
            score += removeSubstrings(s, 'a', 'b', x);
            score += removeSubstrings(s, 'b', 'a', y);

            return score;
        
        }
};