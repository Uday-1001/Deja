// https://leetcode.com/problems/exclusive-time-of-functions

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int>st;
        vector<int>ans(n , 0);
        int prev = 0;

        for(auto log : logs)
        {
            int pos1 = log.find(':');
            int pos2 = log.find(':' , pos1 + 1);

            int id = stoi(log.substr(0 , pos1));
            string status = log.substr(pos1 + 1 , pos2-2);
            int curr_time = stoi(log.substr(pos2 + 1));  

            if(status == "start")
            {
                if(!st.empty())
                {
                    ans[st.top()] += curr_time - prev;
                }
                st.push(id);
                prev = curr_time;
            }
            else if(status == "end")
            {
                if(!st.empty())
                {
                    ans[st.top()] += curr_time - prev + 1;
                }
                st.pop();
                prev = curr_time + 1;
            }
        }
    return ans;
    }
};