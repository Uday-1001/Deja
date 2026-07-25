// https://leetcode.com/problems/count-collisions-on-a-road

class Solution {
public:
    int countCollisions(string directions) {
        stack<char>st;
        int collisions = 0;

        for(int i=0 ; i<directions.size() ; i++)
        {
            if(!st.empty() and st.top() == 'S')
            {
                collisions++;
            }
            else if(!st.empty() and st.top() != directions[i])
            {
                if(directions[i] != 'S')
                {
                    collisions += 2;
                    st.pop();
                }
                else 
                {
                    collisions++;
                    st.push(directions[i]);
                }
            }
            else if(!st.empty() and st.top() == directions[i]) 
            {
                st.pop();
            }
            else 
            st.push(directions[i]);
        }
        return collisions;
    }
};