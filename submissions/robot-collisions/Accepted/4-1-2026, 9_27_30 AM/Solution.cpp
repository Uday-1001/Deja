// https://leetcode.com/problems/robot-collisions

class Solution {
public:
    using ti = tuple<int,int,char,int>;

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<ti>info;
        for(int i = 0 ; i<positions.size() ; i++) info.push_back({positions[i] , healths[i] , directions[i] , i});

        sort(begin(info), end(info));

        stack<ti>st;
        for(int i = 0 ; i<info.size() ; i++)
        {
            auto[pos , health , dir , idx] = info[i];

            while(!st.empty() and get<2>(st.top()) == 'R' and dir == 'L')
            {
                auto[tpos , thealth , tdir , tidx] = st.top();
                st.pop();

                if(health == thealth) 
                {
                    health = 0;
                    break;
                }
                else if(thealth > health)
                {
                    thealth--;
                    st.push({tpos , thealth , tdir , tidx});
                    health = 0;
                    break;
                }
                else health--;
            }

            if(health > 0) st.push({pos , health , dir , idx});
        }

    vector<pair<int,int>>ansformation;
    while(!st.empty())
    {
        auto [pos , health , dir , idx] = st.top();
        st.pop();

        ansformation.push_back({idx , health});
    }
    sort(begin(ansformation) , end(ansformation));

    vector<int>finalans;
    for(auto it : ansformation)
    {
        auto[idx , health] = it;
        finalans.push_back(health);
    }

    return finalans;
    }
};