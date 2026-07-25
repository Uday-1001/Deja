// https://leetcode.com/problems/bitwise-xor-of-all-pairings

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> xor_num(m*n);

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                xor_num.push_back(nums1[i]^nums2[j]);
            }
        }  
        int ans = 0;
        for(auto num : xor_num)
        {
            ans = ans ^ num;
        }
    return ans;      
    }
};