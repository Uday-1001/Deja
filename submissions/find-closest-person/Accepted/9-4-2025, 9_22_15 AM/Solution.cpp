// https://leetcode.com/problems/find-closest-person

class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(abs(z-x) == abs(y-z)) return 0;
        return (abs(z-x) > abs(y-z)) ? 2 : 1;    
    }
};