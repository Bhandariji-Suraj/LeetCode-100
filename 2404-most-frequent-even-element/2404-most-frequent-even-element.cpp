class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
         std::unordered_map<int, int> freqMap; 
        int mostFrequent = -1;
        int maxCount = 0;

        for (int num : nums) {
            if (num % 2 == 0) {
                freqMap[num]++;
                if (freqMap[num] > maxCount || (freqMap[num] == maxCount && num < mostFrequent)) {
                    mostFrequent = num;
                    maxCount = freqMap[num];
                }
            }
        }

        return mostFrequent; 
        
    }
};