class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> primes = {2, 3, 5};
        std::priority_queue<long, std::vector<long>, std::greater<long>> minHeap;
        std::unordered_set<long> seen;

        minHeap.push(1);
        seen.insert(1);

        long currentUgly = 1;

        for (int i = 0; i < n; ++i) {
            currentUgly = minHeap.top();
            minHeap.pop();

            for (int prime : primes) {
                long nextUgly = currentUgly * prime;
                if (seen.find(nextUgly) == seen.end()) {
                    minHeap.push(nextUgly);
                    seen.insert(nextUgly);
                }
            }
        }

        return currentUgly;
    }
};