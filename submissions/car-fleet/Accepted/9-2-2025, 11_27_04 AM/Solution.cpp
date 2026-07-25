// https://leetcode.com/problems/car-fleet

class Solution {
public:
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int car_fleet = 0;
        stack<float>st;
        //making a pair of the defined position and speed according to their originals and sorting them
        vector<pair<int, int>> vp;
        for(int i = 0; i<speed.size(); i++)
        {
            pair<int,int> temp = {position[i], speed[i]};
            vp.push_back(temp);
        }
        sort(vp.begin(), vp.end());

        if(vp.size() == 1) return 1;

        vector<float>calc_time;

        for(auto elem : vp)
        {
            int pos = elem.first;
            int speed = elem.second;

            float time_required = ((target - pos) / (float)speed);
            calc_time.push_back(time_required); 
        }
        
        for(int i=0 ; i<calc_time.size() ; i++)
        {
            float curr_time = calc_time[i];
            
            while(!st.empty() && curr_time >= st.top())
            {
                st.pop();
            }
            st.push(curr_time);
        }
    return st.size();
    }
};