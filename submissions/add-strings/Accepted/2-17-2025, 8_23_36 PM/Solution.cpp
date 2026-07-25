// https://leetcode.com/problems/add-strings

class Solution {
public:
    void helper(string &num1, string &num2, int l1 , int l2 , int carry , string &final_ans)
    {
        // base case
        if(l1 < 0 && l2 < 0)
        {
            if(carry != 0)
            {
                final_ans.push_back(carry + '0');
            }
            return;
        }

        //ek case hum solve karenge .. baaki recursion dekh lega 

        int d1 = (l1 >= 0 ? num1[l1] : '0') - '0';
        int d2 = (l2 >= 0 ? num2[l2] : '0') - '0';

        int sum = d1 + d2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        final_ans.push_back(digit + '0');

        helper(num1 , num2 , l1 - 1 , l2 - 1 , carry , final_ans); 
       
    } 

    string addStrings(string num1, string num2) {
        string final_ans = "";

        helper(num1 , num2 , num1.size()-1 , num2.size()-1 , 0 , final_ans);
        reverse(final_ans.begin() , final_ans.end());

        return final_ans ;
    }
};