// https://leetcode.com/problems/time-needed-to-buy-tickets

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        int n = tickets.size();
        while(true) 
        {
            for(int i = 0; i < n; ++i) 
            {
                if(tickets[i] > 0) 
                {
                    tickets[i]--;
                    time++;
                    if (i == k && tickets[i] == 0) return time;
                }
            }
        }
    return time;
    }
};