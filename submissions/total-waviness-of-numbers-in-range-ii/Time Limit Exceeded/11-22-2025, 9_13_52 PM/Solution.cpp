// https://leetcode.com/problems/total-waviness-of-numbers-in-range-ii

class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        long long peaks = 0;
        long long valleys = 0;
        long long waviness = 0;
        for(int i = num1 ; i<=num2 ; i++){
            string s = to_string(i);
            if(s.size() < 3) waviness = 0;
            for(int j = 1 ; j < s.size()-1 ; j++){
                if(s[j] > s[j+1] && s[j] > s[j-1])
                    peaks++;
                else if(s[j] < s[j+1] && s[j] < s[j-1])
                    valleys++;
            }   
        } 
    waviness = peaks + valleys;
    return waviness;
    }
};