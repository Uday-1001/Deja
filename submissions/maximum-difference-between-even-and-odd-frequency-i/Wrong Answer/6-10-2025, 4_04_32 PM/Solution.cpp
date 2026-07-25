// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mpp;

        for(auto ch : s)
        {
            mpp[ch]++;
        }

        int oddmax = -1;
        int evenmax = -1;
        for(auto it: mpp)
        {
            int a1 = it.second & 1 ? it.second : -1;
            int a2 = (it.second % 2 == 0) ? it.second : -1;

            if(oddmax < a1) oddmax = a1;
            
            if(evenmax < a2) evenmax = a2;
        }
    return (oddmax - evenmax);
    }
};