// https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int result = 0;
        for(auto x : nums){
            if(x == 0){
                zero++;
            }
            result = result ^ x;
        }
        if(zero == n) return 0;
        if(result != 0) return n;
        return n-1;
    }
};