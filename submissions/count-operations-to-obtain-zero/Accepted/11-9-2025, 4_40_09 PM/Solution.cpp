// https://leetcode.com/problems/count-operations-to-obtain-zero

class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        if(num1 == 0 and num2 == 0) return 0;
        if(num1 == num2) return 1;

        while(num1 != 0 && num2 != 0)
        {
            if(num1 > num2)
                num1 -= num2;
            else
                num2 -= num1;
            
            ans++;
        }
        return ans;
    }
};