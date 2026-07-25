// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range

class Solution {
public:
    int countOdds(int low, int high) {
        int odds = (high - low) / 2; 
        if(low & 1) return odds + 1;
        else if(low & 1 and high & 1) return odds + 2;
        else return odds;
    }
};