// https://leetcode.com/problems/final-value-of-variable-after-performing-operations

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(auto opr : operations)
        {
            ans += (opr == "++X" || opr == "X++") ? 1 : -1;
        }
        return ans;
    }
};