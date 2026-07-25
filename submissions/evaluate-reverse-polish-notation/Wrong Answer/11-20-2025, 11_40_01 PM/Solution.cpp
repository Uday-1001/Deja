// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    int operation_done(string &opr , string &a , string &b)
    {
        int first = stoi(a);
        int second = stoi(b);
        if(opr == "+") return first + second;
        if(opr == "-") return (first > second) ? first - second : second - first;
        if(opr == "*") return first * second;
        return (first > second && first != 0 and second != 0) ? first / second : second / first ;
    }

    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        for(auto token : tokens)
        {
            if(token == "+" or token == "-" or token == "*" or token == "/")
            {
                auto first = st.top(); st.pop();
                auto second = st.top(); st.pop();

                string ans = to_string(operation_done(token , first , second));

                st.push(ans);
            }
            else 
            st.push(token);  
        }
        return stoi(st.top());
    }
};