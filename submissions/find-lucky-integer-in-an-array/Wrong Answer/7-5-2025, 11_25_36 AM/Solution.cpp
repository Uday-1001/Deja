// https://leetcode.com/problems/find-lucky-integer-in-an-array

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(auto it : arr)
        {
            mpp[it]++;
        }
        for(auto it : mpp)
        {
            if(it.first == it.second)
            {
                return it.first;
            }
        }
    return -1;
    }
};