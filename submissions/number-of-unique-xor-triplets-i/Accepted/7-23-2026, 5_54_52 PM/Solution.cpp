// https://leetcode.com/problems/number-of-unique-xor-triplets-i

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n <= 2) return n;

        vector<int>poweroftwo(n);
        poweroftwo[0] = 1;

        for(int i = 1 ; i<n ; i++) poweroftwo[i] = poweroftwo[i-1] << 1;

        for(int i = 0 ; i<n ; i++) if(n < poweroftwo[i]) return poweroftwo[i];

        return -1;
    }
};