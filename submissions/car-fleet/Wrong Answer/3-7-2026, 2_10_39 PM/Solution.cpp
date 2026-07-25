// https://leetcode.com/problems/car-fleet

class Solution {
public:
    using pi = pair<int,int>;

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pi>cars;
        for(int i = 0 ; i<speed.size() ; i++)
        {
            int pos = position[i];
            int s = speed[i];

            cars.push_back({pos , s});
        }

        if(cars.size() == 1) return 1;
        sort(cars.begin() , cars.end());

        vector<int>time;
        for(auto it : cars)
        {
            auto[pos , speed] = it;
            time.push_back((target - pos) / speed);
        }

        vector<int>st;
        for(auto it : time)
        {
            int curr = it;
            while(!st.empty() and curr >= st.back()) st.pop_back();
            st.push_back(curr);
        }
    return st.size();
    }
};