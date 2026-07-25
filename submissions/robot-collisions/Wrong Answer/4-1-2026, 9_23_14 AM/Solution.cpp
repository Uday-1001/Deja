// https://leetcode.com/problems/robot-collisions

class Solution {
public:
    using ti = tuple<int,int,char>;

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<ti>info;
        for(int i = 0 ; i<positions.size() ; i++) info.push_back({positions[i] , healths[i] , directions[i]});

        sort(begin(info), end(info));

        stack<ti>st;
        for(int i = 0 ; i<info.size() ; i++)
        {
            auto[pos , health , dir] = info[i];

            while(!st.empty() and get<2>(st.top()) == 'R' and dir == 'L')
            {
                auto[tpos , thealth , tdir] = st.top();
                st.pop();

                if(health == thealth) 
                {
                    health = 0;
                    break;
                }
                else if(thealth > health)
                {
                    thealth--;
                    st.push({tpos , thealth , tdir});
                    health = 0;
                    break;
                }
                else health--;
            }

            if(health > 0) st.push({pos , health , dir});
        }

    vector<int>ans;
    while(!st.empty())
    {
        auto [pos , health , dir] = st.top();
        st.pop();

        ans.push_back(health);
    }
    return ans;
    }
};