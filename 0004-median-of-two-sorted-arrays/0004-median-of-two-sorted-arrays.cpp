class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //Merging both arrays
        //M-1
        for(int i =0;i< nums2.size();i++)
        {
            nums1.push_back(nums2[i]);
        }

        //M-2
        // nums1.insert(nums1.end(),nums2.begin(),nums2.end());

        //Sorting the final array
        sort(nums1.begin(), nums1.end());
        int n = nums1.size();
        int mid = n/2;
        if(n%2==0)return (nums1[mid-1] + nums1[mid])/2.0;
        else return nums1[mid];
    }
};