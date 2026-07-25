// https://leetcode.com/problems/minimum-time-to-make-rope-colorful

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<pair<char , int>>st;

        st.push({colors[0] , neededTime[0]});

        int sum = 0;
        for(int i=1 ; i <colors.size() ; i++)
        {
            auto[color , time] = st.top();
            if(colors[i] == color && time > neededTime[i])
            {
                sum += neededTime[i];
            }
            else if(colors[i] == color && time <= neededTime[i])
            {
                auto[color , time] = st.top(); st.pop();
                sum += time;
                st.push({colors[i] , neededTime[i]});
            }
            else
            {
                st.push({colors[i] , neededTime[i]});
            }
        }
    return sum;
    }
};