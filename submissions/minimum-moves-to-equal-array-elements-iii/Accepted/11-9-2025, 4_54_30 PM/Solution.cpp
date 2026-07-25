// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = accumulate(begin(nums) , end(nums) , 0);
        int max_elem = *max_element(begin(nums) , end(nums));
        int req_sum = max_elem * nums.size();

        return req_sum - sum;
    }
};