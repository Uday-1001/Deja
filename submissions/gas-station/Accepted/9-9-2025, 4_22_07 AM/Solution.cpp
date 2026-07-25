// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0;
        int extra_gas = 0;
        int start = 0;

        for(int i=0 ; i<gas.size() ; i++)
        {
            extra_gas += gas[i] - cost[i];

            if(extra_gas < 0)
            {
                //means deficit has occured for gas
                deficit += abs(extra_gas);
                start = i+1;
                extra_gas = 0;
            }
        }
    return (extra_gas - deficit >= 0) ? start : -1;
    }
};