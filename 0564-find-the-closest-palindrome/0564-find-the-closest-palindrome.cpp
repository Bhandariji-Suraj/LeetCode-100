class Solution {
public:
    // Define createPalindrome inside the Solution class
    string createPalindrome(string half, bool evenLength) {
        string palin = half;
        if (!evenLength) {
            half.pop_back();  // Remove the middle digit for odd length numbers
        }
        reverse(half.begin(), half.end());
        palin += half;
        return palin;
    }

    string nearestPalindromic(string n) {
        int len = n.length();
        if (len == 1) {
            return to_string(stoi(n) - 1);
        }

        vector<string> candidates;

        // Middle segment manipulation
        string prefix = n.substr(0, (len + 1) / 2);

        // Create three main candidates
        long long prefixNum = stoll(prefix);
        candidates.push_back(createPalindrome(to_string(prefixNum), len % 2 == 0));
        candidates.push_back(createPalindrome(to_string(prefixNum - 1), len % 2 == 0));
        candidates.push_back(createPalindrome(to_string(prefixNum + 1), len % 2 == 0));

        // Handle edge cases: 10...01 and 99...99
        candidates.push_back("1" + string(len - 1, '0') + "1");  // 100...001
        candidates.push_back(string(len - 1, '9'));  // 99...999

        string closest;
        long long originalNum = stoll(n);
        long long minDiff = LLONG_MAX;

        for (const string& candidate : candidates) {
            long long candidateNum = stoll(candidate);
            if (candidateNum == originalNum) continue;

            long long diff = abs(candidateNum - originalNum);
            if (diff < minDiff || (diff == minDiff && candidateNum < stoll(closest))) {
                minDiff = diff;
                closest = candidate;
            }
        }

        return closest;
    }
};