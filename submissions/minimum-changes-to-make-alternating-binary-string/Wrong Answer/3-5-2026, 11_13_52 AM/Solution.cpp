// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int ones = 0 , zeros = 0;

        for(auto it : s)
        {
            if(it == '0') zeros++;
            else ones++;
        }

        if(ones == zeros) return 0;

        int ones_opr = (n/2) - ones;
        int zeros_opr = (n/2) - zeros;

        return abs(ones_opr) > abs(zeros_opr) ? abs(zeros_opr) : abs(ones_opr);
    }
};