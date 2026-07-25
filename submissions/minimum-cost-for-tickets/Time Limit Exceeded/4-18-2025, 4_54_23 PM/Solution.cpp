// https://leetcode.com/problems/minimum-cost-for-tickets

class Solution {
public:
    int recursion(vector<int>& days, vector<int>& cost , int i)
    {
        //base case
        if(i >= days.size()) return 0;

        //ek case hum sove karenge baaki recursion sambhalega

        // 1 Day Pass
        int cost_pass1 = cost[0] + recursion(days ,cost , i+1);

        // 7 Day Pass
        int j = i;
        int pass_end_date = days[j] + 7 - 1;
        while(j < days.size() && days[j] <= pass_end_date)
        {
            j++;
        }
        int cost_pass2 = cost[1] + recursion(days , cost , j);

        // 30 Day Pass
        j = i;
        pass_end_date = days[j] + 30 - 1;
        while(j < days.size() && days[j] <= pass_end_date)
        {
            j++;
        }
        int cost_pass3 = cost[2] + recursion(days , cost , j);

        //calculate min cost of all costs
        int min_cost = min(cost_pass1 , min(cost_pass2 , cost_pass3));
        return min_cost;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return recursion(days , costs , 0);
    }
};