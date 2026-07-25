// https://leetcode.com/problems/count-mentions-per-user

class Solution {
public:
    static bool mycomp(const vector<string>&a , const vector<string>&b)
    {
        return stoi(a[1]) < stoi(b[1]);
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = numberOfUsers;
        vector<int>ans(n , 0);
        vector<bool>online(n , true);
        vector<int>offline_until(n , 0);

        for(auto &event : events)
        {
            sort(events.begin() , events.end() , mycomp);
        }

        for(auto event : events)
        {
            string mssg = event[0];
            int timestamp = stoi(event[1]);
            string data = event[2];

            //restoring the online state if the time expires
            for(int i =0 ; i<n ; i++)
            {
                if(!online[i] and offline_until[i] <= timestamp) online[i] = true;
            }

            if(mssg == "OFFLINE")
            {
                int id = stoi(data);
                online[id] = false;
                offline_until[id] = timestamp + 60;
            }
            else if(mssg == "MESSAGE")
            {
                if(data == "HERE")
                {
                    //only online users ko mention karo
                    for(int i =0 ; i<n ; i++) 
                    {
                        if(online[i] == true) ans[i]++;
                    }
                }
                else if(data == "ALL")
                {
                    //all users ko mention karo
                    for(int i =0; i<n ; i++) ans[i]++;
                }
                else 
                {
                    //stream of data i.e id<number>list ko parse bhi to karna hai..
                    int s = 0 , e = data.size();
                    while(s < e)
                    {
                        while(s < data.size() and data[s] == ' ') s++;

                        if(s < data.size() and data[s] == 'i' and s+1 < data.size() and data[s+1] == 'd')
                        s += 2;

                        int num = 0;
                        while(s < data.size() and isdigit(data[s]))
                        {
                            num = num * 10 + (data[s] - '0');
                            s++;
                        }
                        ans[num]++;
                    }
                }
            }
        }
    return ans;
    }
};