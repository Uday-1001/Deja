// https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i

class Solution {
public:
    using ti = tuple<int,int,int>;

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<ti>events;
        for(int i = 0 ; i<n ; i++) events.push_back({landStartTime[i] , landDuration[i] , 1});
        
        for(int i = 0 ; i<m ; i++) events.push_back({waterStartTime[i] , waterDuration[i] , 0});

        sort(begin(events) , end(events));

        bool landdone = false , waterdone = false;
        int time = 0;

        for(auto it : events)
        {
            int type = get<2>(it);
            int duration = get<1>(it);
            int st = get<0>(it);

            if(landdone and waterdone) break;

            if(!landdone and !waterdone)
            {
                time += st;
                time += duration;
                if(type == 1) landdone = true;
                else waterdone = true;
            }
            else if(!landdone)
            {
                int waiting_time = st - time;
                if(waiting_time > 0) time += waiting_time;
                time += duration;
                landdone = true;
            }
            else
            {
                int waiting_time = st - time;
                if(waiting_time > 0) time += waiting_time;
                time += duration;
                waterdone = true;
            }
        }
        return time;
    }
};