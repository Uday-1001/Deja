// https://leetcode.com/problems/water-bottles-ii

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total_drunk = numBottles;
        int emptied = numBottles;

        while(emptied >= numExchange)
        {
            emptied = emptied - numExchange;
            numExchange++;

            //emptied bottle ke exchange me maine jo bottle li thi vo pi li
            total_drunk++;
            //usko peene ke baad vo wali bottle bhi khali ho gyi 
            emptied++;
        }
    return total_drunk;
    }
};