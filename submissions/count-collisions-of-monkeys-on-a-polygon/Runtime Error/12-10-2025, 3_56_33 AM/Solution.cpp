// https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon

class Solution {
public:
    int monkeyMove(int n) {
        return pow(2 , n) - 2;
    }
};