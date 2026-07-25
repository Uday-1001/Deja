// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits

class Solution {
public:
    using pi = pair<int,int>;
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin() , arr.end() , [](int a , int b)
        {
            int x = __builtin_popcount(a);
            int y = __builtin_popcount(b);

            if(x == y) return a < b;
            return x < y;
        });
    return arr;
    }
};