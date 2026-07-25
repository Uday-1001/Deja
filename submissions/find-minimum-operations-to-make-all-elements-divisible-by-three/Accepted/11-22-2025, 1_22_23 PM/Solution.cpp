// https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int opr = 0;
        for(auto num : nums)
        {
            if(num % 3 != 0) opr++;
        }
    return opr;
    }
};