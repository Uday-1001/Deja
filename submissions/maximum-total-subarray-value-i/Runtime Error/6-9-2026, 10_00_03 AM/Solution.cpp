// https://leetcode.com/problems/maximum-total-subarray-value-i

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        return k * (*max_element(begin(nums) , end(nums)) - *min_element(begin(nums) , end(nums)));
    }
};