// https://leetcode.com/problems/mirror-frequency-distance

class Solution {
public:
    int mirrorFrequency(string s) {
        int letters[26] = {0};
        int digits[10] = {0};

        for(char ch : s){
            if(ch >= 'a' and ch <= 'z') letters[ch - 'a']++;
            else if(ch >= '0' and ch <= '9') digits[ch - '0']++;
        }

        int sum = 0;
        for(int i = 0 ; i<13 ; i++){
            if(letters[i] > 0 or letters[25 - i] > 0) sum += abs(letters[i] - letters[25-i]);
        }
        for(int i = 0 ; i<5 ; i++){
            if(digits[i] > 0 or digits[9 - i] > 0) sum += abs(digits[i] - digits[9-i]);
        }
        return sum;
    }
};