// https://leetcode.com/problems/find-greatest-common-divisor-of-array

class Solution {
public:
    int findGCD(vector<int>& nums) {
        return gcd(*min_element(begin(nums) , end(nums)) , *max_element(begin(nums) , end(nums)));
    }
};