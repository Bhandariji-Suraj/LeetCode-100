class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string> distinct_strings;
        for (int i = 0; i < arr.size(); i++) {
            int count = 0;
            for (int j = 0; j < arr.size(); j++) {
                if (arr[i] == arr[j]) {
                    count++;
                }
            }
            if (count == 1) {
                distinct_strings.push_back(arr[i]);
            }
        }

        if (k <= distinct_strings.size()) {
            return distinct_strings[k - 1];
        } else {
            return "";
        }
        
    }
};