// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range

class Solution {
public:
    int countOdds(int low, int high) {
        int size = high - low + 1;
        if(!(size & 1)) return size/2;
        else 
        {
            if(low & 1 and high & 1) return size / 2 + 1;
            else return size / 2;
        }
    }
};