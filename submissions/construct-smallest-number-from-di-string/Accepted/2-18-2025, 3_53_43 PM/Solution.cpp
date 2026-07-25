// https://leetcode.com/problems/construct-smallest-number-from-di-string

class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        stack<int>st;
        string result = "";

        for(int i = 1 ; i<=n+1 ; i++)
        {
            st.push(i);
            char c =  pattern[i-1];

            if(i == n+1 or c == 'I')
            {
                while(!st.empty())
                {
                    result.push_back('0' + st.top());
                    st.pop();
                }
            }
        }
    return result;
    }
};