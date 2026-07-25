// https://leetcode.com/problems/minimum-string-length-after-balanced-removals

class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int countA = 0;
        int countB = 0;
        for(auto ch : s){
            if(ch == 'a') countA++;
            else countB++;
        }
        return (countA > countB) ? countA-countB : countB-countA;
    }
};