// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid

class Solution {
public:
    bool canBeValid(string s, string locked) {
         int n = s.length();
        if(n&1) return false;
        
        stack<int> st;
        stack<int> unlocked;
        for(int i=0 ; i<n ; i++)
        {
            char ch = s[i];
            char state = locked[i];
            if(state == '0')
            {
                unlocked.push(i);
            }
            else if(ch =='(')
            {
                st.push(i);
            }
            else
            {
                if(!st.empty())
                {
                    st.pop();
                }
                else
                {
                    if(!unlocked.empty())
                    {
                        unlocked.pop();
                    }
                    else
                    {
                    return false;
                    }
                }
            }
        }
        while(!st.empty() && !unlocked.empty() && st.top() < unlocked.top())
        {
            st.pop();
            unlocked.pop();
        }
        return (st.empty());
    }
};