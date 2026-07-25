// https://leetcode.com/problems/maximum-ice-cream-bars

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int max_elem = *max_element(begin(costs) , end(costs));

        vector<int>slots(max_elem + 1 , 0);
        for(auto it : costs) slots[it]++;

        int icecreams = 0;

        for(int i = 0 ; i<slots.size() ; i++)
        {
            if(slots[i] == 0) continue;

            long long currcost = slots[i] * i;
            if(currcost <= coins)
            {
                coins -= currcost;
                icecreams += slots[i];
            }
            else 
            {
                icecreams += (coins / i);
                break;
            }
        }
        return icecreams;
    }
};