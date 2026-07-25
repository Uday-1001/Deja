// https://leetcode.com/problems/bitwise-xor-of-all-pairings

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int result = 0;
         
        if(n & 1)
        {
            for(auto it : nums2)
            {
                result ^= it;
            }
        }
        
        if(m & 1)
        {
            for(auto it : nums1)
            {
                result ^= it;
            }
        }
    return result;         
    }
};