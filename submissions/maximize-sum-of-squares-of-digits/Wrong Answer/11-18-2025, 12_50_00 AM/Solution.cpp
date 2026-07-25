// https://leetcode.com/problems/maximize-sum-of-squares-of-digits

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        int digit_count = 0;
        int req_sum = sum;

        if(num == 1 and sum >= 10) return "";
        
        for(int i=9 ; i>=0 ; i--)
        {
            if(i <= req_sum) 
            {
                ans.push_back(i + '0');
                req_sum -= i;
                digit_count++;
            }
            if(digit_count == num) break;
        }
    return ans;
    }
};