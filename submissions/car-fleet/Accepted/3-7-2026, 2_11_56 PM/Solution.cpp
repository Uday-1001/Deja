// https://leetcode.com/problems/car-fleet

class Solution {
public:
    using pi = pair<float,float>;

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pi>cars;
        for(int i = 0 ; i<speed.size() ; i++)
        {
            auto pos = position[i];
            auto s = speed[i];

            cars.push_back({pos , s});
        }

        if(cars.size() == 1) return 1;
        sort(cars.begin() , cars.end());

        vector<float>time;
        for(auto it : cars)
        {
            auto[pos , speed] = it;
            time.push_back((target - pos) / speed);
        }

        vector<float>st;
        for(auto it : time)
        {
            auto curr = it;
            while(!st.empty() and curr >= st.back()) st.pop_back();
            st.push_back(curr);
        }
    return st.size();
    }
};