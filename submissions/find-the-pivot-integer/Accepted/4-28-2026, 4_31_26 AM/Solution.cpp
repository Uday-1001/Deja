// https://leetcode.com/problems/find-the-pivot-integer

class Solution {
public:
    int pivotInteger(int n) {
        int total = (n * (n+1)) / 2;

        int left = 0;
        int right = total;

        for(int i = 1 ; i<=n ; i++)
        {
            left += i;
            if(left == right) return i;
            right -= i;
        }
        return -1;
    }
};