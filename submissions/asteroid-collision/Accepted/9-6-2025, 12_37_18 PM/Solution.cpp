// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;

        for(auto asteroid : asteroids)
        {   
            while(!st.empty() && st.top() > 0 && asteroid < 0)
            {
                int sum = st.top() + asteroid;

                //means that the tos asteroid is larger and hence resultant is right 
                if(sum > 0) 
                {
                    asteroid = 0;
                }
                //means that both tos asteroid and current are same so reultant is both dusted
                else if(sum == 0) 
                {
                    st.pop(); 
                    asteroid = 0;
                }
                //means that the current asteroid is larger hence resultant is left
                else 
                {
                    st.pop();
                }
            }

            if(asteroid != 0)
            {
                st.push(asteroid);
            }
        }
        int s = st.size();
        vector<int>ans(s);
        int i = s-1;

        while(!st.empty())
        {
            ans[i] = st.top();
            st.pop();
            i--;
        }
    return ans;
    }
};