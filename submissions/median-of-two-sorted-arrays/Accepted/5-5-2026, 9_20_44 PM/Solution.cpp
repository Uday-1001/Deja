// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>merged;

        int i = 0 , j = 0;
        while(i < n and j < m)
        {
            if(nums1[i] <= nums2[j])
            {
                merged.push_back(nums1[i++]);
            }  
            else merged.push_back(nums2[j++]);
        }
        while(i < n) merged.push_back(nums1[i++]);
        while(j < m) merged.push_back(nums2[j++]);

        double ans = 0;

        int s = 0;
        int e = merged.size()-1;
        int mid = s + (e-s) / 2;
            
        return (merged.size() & 1) ? merged[mid] : ((merged[mid] + merged[mid+1]) / 2.0);
    }
};