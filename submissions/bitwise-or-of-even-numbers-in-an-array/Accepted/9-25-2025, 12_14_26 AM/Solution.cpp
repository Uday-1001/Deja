// https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array

class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int result = 0;
        for(auto x :nums)
        {
            if(!(x&1))
            {
                result = result | x;
            }
        }
    return result;
    }
};