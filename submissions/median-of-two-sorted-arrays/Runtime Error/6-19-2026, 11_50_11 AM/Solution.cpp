// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();

        if(n & 1) return min(nums1[nums1.size()-1] , nums2[0]);
        else return (nums1[nums1.size()-1] + nums2[0]) / 2.0;
    }
};