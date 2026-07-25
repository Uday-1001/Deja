// https://leetcode.com/problems/water-bottles

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;

        while(numExchange <= numBottles)
        {
            int filled = numBottles / numExchange;
            int emptied = numBottles % numExchange;

            total += filled;

            numBottles = filled + emptied;
        }
        return total;
    }
};