// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;

        string ans = "";

        for(int i=0; i<num.size() ; i++)
        {
            char n = num[i];

            //pop when the number in the stack is greater than the curr num as it will be removed first
            while(!st.empty() && st.top() > n && k != 0)
            {
                st.pop();
                k--;
            }
            st.push(n);
        }

        //if k is still left then pop the digits
        // while(k>0 && !st.empty())
        // {
        //     st.pop();
        //     k--;
        // }

        //building the answer and then reversing it
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(begin(ans) , end(ans));

        //removing the leading zeros 
        int i = 0;
        string final_ans = "";
        while(i < ans.size() && ans[i] == '0')
        {
            i++;
        }
        final_ans = ans.substr(i);

        return final_ans.empty() ? "0" : final_ans;
    }
};