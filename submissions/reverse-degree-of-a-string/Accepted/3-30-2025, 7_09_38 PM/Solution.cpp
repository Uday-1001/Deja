// https://leetcode.com/problems/reverse-degree-of-a-string

class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int j = 1;
       for(int i = 0 ; i<s.size(); i++)
        {
            sum += (int)('z'- s[i] + 1) * j;
            j++;
        }
        return sum;
    }
};