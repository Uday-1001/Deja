// https://leetcode.com/problems/vowels-game-in-a-string

class Solution {
public:
    bool doesAliceWin(string s) {
        int vowel_count = 0;
        //got the vowel count
        for(auto ch : s)
        {
            if(ch == 'a' || ch == 'e' ||ch == 'i'||ch == 'o'||ch == 'u') 
            vowel_count++;
        }

        if(vowel_count == 0)
        {
            return false;
        }
        else
            return true;
    }
};