// https://leetcode.com/problems/basic-calculator

class Solution {
public:
    int calculate(string s) {
        stack<int>st;

        //initially yhi hoga 
        int number = 0;
        int result = 0;
        int sign = 1;

        //iterate kro string pr jabtk 'i' valid index hai
        for(int i=0 ; i<s.size() ; i++)
        {
            //agar digit mile to full number bnao pehle 
            if(isdigit(s[i]))
            {
                number = (number * 10) + (s[i] - '0');
            }
            //agar sign me tumko plus mile to...
            else if(s[i] == '+')
            {
                result += number * sign;
                number = 0;
                sign = 1;
            }
            //agar sign me tumko minus mile to...
            else if(s[i] == '-')
            {
                result += number * sign;
                number = 0;
                sign = -1;
            }
            //agar open bracket mil jaaye to...
            else if(s[i] == '(')
            {
                //iska mtlb BODMAS rule me isko priority do aur pehle solve kro
                //pichla result ko push krdo aur sign ko bhi 
                st.push(result);
                st.push(sign);
                result = 0;
                number = 0;
                sign = 1;
            }
            else if(s[i] == ')')
            {
                //agar closing bracket mil jaaye to...
                //solve kra hua result ko final ans me add krlo
                result += (number * sign);
                number = 0;

                int stack_sign = st.top();
                st.pop();
                int last_result = st.top();
                st.pop();

                result *= stack_sign;
                result += last_result;
            }
        }
    result += (number * sign);
    return result;
    }
};