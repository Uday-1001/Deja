// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();

        if(nums1.size() == 0)
        {
            if(nums2.size() & 1) return nums2[nums2.size()/2];
            else return (nums2[nums2.size()/2] + nums2[nums2.size()/2 + 1]) / 2.0;
        }
        if(nums2.size() == 0)
        {
            if(nums1.size() & 1) return nums1[nums1.size()/2];
            else return (nums1[nums1.size()/2] + nums1[nums1.size()/2 + 1]) / 2.0;
        }

        if(n & 1) return min(nums1[nums1.size()-1] , nums2[0]);
        else return (nums1[nums1.size()-1] + nums2[0]) / 2.0;
    }
};