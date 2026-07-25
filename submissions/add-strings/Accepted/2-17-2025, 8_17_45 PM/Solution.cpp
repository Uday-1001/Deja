// https://leetcode.com/problems/add-strings

class Solution {
public:
    string helper(string &num1, string &num2, int l1 , int l2 , int carry)
    {
        // base case
        if(l1 < 0 && l2 < 0)
        {
            if(carry != 0)
            {
                return string(1 , carry + '0');
            }
            return "";
        }

        //ek case hum solve karenge .. baaki recursion dekh lega 
        string ans = "";

        int d1 = (l1 >= 0 ? num1[l1] : '0') - '0';
        int d2 = (l2 >= 0 ? num2[l2] : '0') - '0';

        int sum = d1 + d2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        ans.push_back(digit + '0');

        ans += helper(num1 , num2 , l1 - 1 , l2 - 1 , carry); 
        return ans;
    } 

    string addStrings(string num1, string num2) {
        string final_ans = "";

        final_ans  = helper(num1 , num2 , num1.size()-1 , num2.size()-1 , 0);
        reverse(final_ans.begin() , final_ans.end());
        
        return final_ans ;
    }
};