// https://leetcode.com/problems/asteroid-collision

class Solution {
public:

    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;

        bool destroyed = false;

        for(auto asteroid : asteroids)
        {
            //if the number is negative but the absolute value of it is larger -> pop the stack
            while(!st.empty() && asteroid < 0 && st.top() > 0)
            {
                if(abs(asteroid) > st.top())
                {
                    st.pop();
                    continue;
                }
                else if(abs(asteroid) == st.top())
                {
                    st.pop();
                    destroyed = true;
                }
                else 
                {
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed) st.push(asteroid);
        }
        //collect answer from the stack
        vector<int>ans(st.size());

        for(int i=st.size()-1 ; i>=0 ; i--)
        {
            ans[i] = st.top();
            st.pop();
        }
    return ans; 
    }
};