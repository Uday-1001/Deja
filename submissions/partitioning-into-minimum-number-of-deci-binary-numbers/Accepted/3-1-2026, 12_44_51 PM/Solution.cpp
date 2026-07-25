// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers

class Solution {
public:
    int minPartitions(string n) {
        int maxi = INT_MIN;
        for(auto it : n)
        {
            maxi = max(maxi , it-'0');
        }
    return maxi;
    }
};