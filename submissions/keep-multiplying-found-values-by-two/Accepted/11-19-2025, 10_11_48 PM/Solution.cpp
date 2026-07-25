// https://leetcode.com/problems/keep-multiplying-found-values-by-two

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        // int ans = original;
        unordered_set<int>st(nums.begin() , nums.end());
        while(st.count(original))
            original *= 2;
         
        return original;
    }
};