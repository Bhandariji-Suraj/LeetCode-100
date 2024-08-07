class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1); 

        for (int i = 0; i < nums1.size(); i++) {
            int temp = nums1[i];
            bool found = false;

            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == temp) {
                    for (int k = j + 1; k < nums2.size(); k++) {
                        if (nums2[k] > temp) {
                            res[i] = nums2[k];
                            found = true;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return res;
        
    }
};