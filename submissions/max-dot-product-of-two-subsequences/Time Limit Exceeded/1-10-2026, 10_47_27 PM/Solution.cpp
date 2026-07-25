// https://leetcode.com/problems/max-dot-product-of-two-subsequences

class Solution {
public:
    int byrec(vector<int>& nums1, vector<int>& nums2 , int i , int j)
    {
        if(i >= nums1.size() or j >= nums2.size()) return INT_MIN;

        int include = INT_MIN;
        for(int k = j ; k < nums2.size() ; k++)
        {
            include = max(include , ((nums1[i] * nums2[k]) + max(0 , byrec(nums1 , nums2 , i+1 , k+1)))); 
        }
        int exclude = 0 + byrec(nums1 , nums2 , i+1 , j);

        return max(include , exclude);
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        return byrec(nums1 , nums2 , 0 , 0);
    }
};