// https://leetcode.com/problems/count-commas-in-range-ii

class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;
        long long m = 1000;

        while(n >= m){
            count += (n - m + 1);
            m *= 1000;
        }
        return count;
    }
};