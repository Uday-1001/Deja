// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>arr;
        for(auto it : grid) for(auto x : it) arr.push_back(x);

        sort(begin(arr) , end(arr));

        int median = arr[arr.size()/2];

        int oprs = 0;
        for(auto it : arr)
        {
            int diff = (abs(median - it));

            if(diff % x != 0) return -1;
            oprs += diff / x;
        }
        return oprs;        
    }
};