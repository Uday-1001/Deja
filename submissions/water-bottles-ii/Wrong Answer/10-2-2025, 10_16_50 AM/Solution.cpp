// https://leetcode.com/problems/water-bottles-ii

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total = numBottles;

        while(numExchange <= numBottles)
        {
            int filled = 0;

            int emptied = numBottles - numExchange;
            filled++;
            numExchange++;

            while(emptied >= numExchange)
            {
                filled  += emptied / numExchange;
                emptied = emptied - numExchange;
            }

            total += filled;
            numBottles = filled + emptied;
        }
    return total;
    }
};