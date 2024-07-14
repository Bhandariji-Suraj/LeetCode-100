class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> stack;
        stack.push({});

        int i = 0;
        int n = formula.size();

        while (i < n) {
            if (formula[i] == '(') {
                stack.push({});
                i++;
            } else if (formula[i] == ')') {
                auto top = stack.top();
                stack.pop();
                i++;

                int multiplier = 1;
                if (i < n && isdigit(formula[i])) {
                    int i_start = i;
                    while (i < n && isdigit(formula[i])) {
                        i++;
                    }
                    multiplier = stoi(formula.substr(i_start, i - i_start));
                }

                for (auto& [elem, count] : top) {
                    stack.top()[elem] += count * multiplier;
                }
            } else {
                int i_start = i++;
                while (i < n && islower(formula[i])) {
                    i++;
                }
                string elem = formula.substr(i_start, i - i_start);

                int count = 1;
                if (i < n && isdigit(formula[i])) {
                    int i_start_count = i;
                    while (i < n && isdigit(formula[i])) {
                        i++;
                    }
                    count = stoi(formula.substr(i_start_count, i - i_start_count));
                }

                stack.top()[elem] += count;
            }
        }

        auto resultCounter = stack.top();
        stack.pop();

        // Convert map to vector and sort alphabetically
        vector<pair<string, int>> sortedElements(resultCounter.begin(), resultCounter.end());
        sort(sortedElements.begin(), sortedElements.end());

        string result;
        for (auto& [elem, count] : sortedElements) {
            result += elem;
            if (count > 1) {
                result += to_string(count);
            }
        }

        return result;
        
    }
};