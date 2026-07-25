// https://leetcode.com/problems/car-fleet

class Solution {
public:
    vector<int> nextgreater(vector<int>&calc_time)
    {
        stack<int>st;
        st.push(-1);

        vector<int>nextgreater(calc_time.size() , -1);

        for(int i=calc_time.size()-1 ; i>=0 ; i--)
        {
            int element = calc_time[i];

            while(st.top() != -1 && (calc_time[st.top()] < element))
            {
                st.pop();
            }
            nextgreater[i] = st.top();
            st.push(i);
        }
    return nextgreater;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //making a pair of the defined position and speed according to their originals and sorting them
        vector<pair<int, int>> vp;
        for(int i = 0; i<speed.size(); i++)
        {
            pair<int,int> temp = {position[i], speed[i]};
            vp.push_back(temp);
        }
        sort(vp.begin(), vp.end());

        vector<int>calc_time;

        for(auto elem : vp)
        {
            int pos = elem.first;
            int speed = elem.second;

            int time_required = (target - pos) / speed;
            calc_time.push_back(time_required); 
        }

        auto next = nextgreater(calc_time);
        
        int car_fleet = 0;

        for(auto elem : next)
        {
            if(elem == -1) car_fleet++;
        }

        return car_fleet;
    }
};