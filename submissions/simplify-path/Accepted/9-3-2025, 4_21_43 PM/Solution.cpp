// https://leetcode.com/problems/simplify-path

class Solution {
public:
    void Finalans(stack<string>&st , string &ans)
    {
        //base case 
        if(st.empty()) return;

        string top_elem = st.top();
        st.pop();

        Finalans(st , ans);
        ans += top_elem;
    }

    string simplifyPath(string path) {
        stack<string>st;

        int i = 0;
    
        while(i < path.size())
        {
            int start = i;
            int end = i+1;

            while(end < path.size() && path[end] != '/')
            {
                end++;
            }
            //take out a part of the dtring that is just behind the backslashes
            string part = path.substr(start , end-start);
            i = end;

            if(part == "/" || part == "/.")
            {
                continue;
            }
            
            if(part != "/..")
            {
                st.push(part);
            }
            else
            {
                if(!st.empty()) st.pop();
            }
        }
        //now reverse the stack for the desired answer string as the answer produced is reverted 
        string ans = st.empty() ? "/" : "";

        Finalans(st , ans);

        return ans;
    }
};