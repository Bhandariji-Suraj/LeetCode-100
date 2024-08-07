class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreaterMap; 
        vector<int> result;

        stack<int> st;
        
        for (int i = 0; i < nums2.size(); i++) {
            int num = nums2[i];
            
            while (!st.empty() && st.top() < num) {
                int topElement = st.top(); 
                nextGreaterMap[topElement] = num; 
                st.pop();
            }
            st.push(num); 
        }
        
        for (int i = 0; i < nums1.size(); i++) {
            int num = nums1[i]; 
            if (nextGreaterMap.find(num) != nextGreaterMap.end()) {
                result.push_back(nextGreaterMap[num]); 
            } else {
                result.push_back(-1); 
            }
        }

        return result;
        
    }
};