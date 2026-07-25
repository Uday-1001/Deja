// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>arr;
        for(auto it : grid) for(auto x : it) arr.push_back(x);

        sort(begin(arr) , end(arr));

        set<int>remainder;
        for(auto it : arr) remainder.insert(it % x);

        if(remainder.size() != 1) return -1;

        int median = arr[arr.size()/2];

        int oprs = 0;
        for(auto it : arr)
        {
            oprs += (abs(median - it)) / x;
        }
        return oprs;        
    }
};