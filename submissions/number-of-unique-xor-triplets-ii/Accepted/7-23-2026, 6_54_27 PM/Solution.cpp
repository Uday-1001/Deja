// https://leetcode.com/problems/number-of-unique-xor-triplets-ii

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int>pairXor;
        unordered_set<int>ans;

        for(int i = 0 ; i<n ; i++) for(int j = i ; j<n ; j++) pairXor.insert(nums[i] ^ nums[j]);

        for(auto x : pairXor) for(auto num : nums) ans.insert(x ^ num);

        return ans.size();
    }
};