// https://leetcode.com/problems/car-pooling

class Solution {
public:
    static bool mycomp(const pair<int,int>&a , const pair<int,int>&b)
    {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>>events;

        for(auto &it : trips)
        {
            int passengers = it[0];
            int st = it[1];
            int end = it[2];

            events.push_back({st , passengers});
            events.push_back({end , -passengers});
        }

        sort(events.begin() , events.end() , mycomp);

        int total = 0;
        for(int i = 0 ; i<events.size() ; i++)
        {
            auto[pt , delta] = events[i];
            total += delta;
            if(total > capacity) return false;
        }
        
        return true;
    }
};