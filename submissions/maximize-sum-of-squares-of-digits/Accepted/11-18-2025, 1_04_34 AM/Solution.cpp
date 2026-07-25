// https://leetcode.com/problems/maximize-sum-of-squares-of-digits

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        int digit_count = 0;
        int req_sum = sum;
        int digit = 9;
        
        while(digit_count != num)
        {
            if(digit <= req_sum) 
            {
                ans.push_back(digit + '0');
                req_sum -= digit;
                digit_count++;
            }
            else digit--;            
        }
    return (req_sum != 0) ? "" : ans;
    }
};