class Solution {
public:
    int minimizedStringLength(string s) {
        vector<int> freq(26, 0);
        for (char c : s) 
        {
            freq[c - 'a']++;
        }
        vector<bool> used(26, false);
        string res;

        for (char c : s) 
        {
            freq[c - 'a']--; // Decrease frequency as we process each character

            if (used[c - 'a']) 
            {
                continue; // Skip if character already used in result
            }

            // Maintain lexicographical order
            while (!res.empty() && res.back() > c && freq[res.back() - 'a'] > 0) 
            {
                used[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(c); // Add current character to result
            used[c - 'a'] = true;
        }
        int ans = res.size();

        return ans;
        
    }
};