// https://leetcode.com/problems/maximum-number-of-balloons

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;

        for(auto it : text) mp[it]++;
        int words_formed = 0;

        while(mp.count('b') and mp.count('a') and mp.count('l') and mp.count('o') and mp.count('n'))
        {
            words_formed++;
            mp['b']--;
            if(mp['b'] == 0) mp.erase('b');
            mp['a']--;
            if(mp['a'] == 0) mp.erase('a');
            mp['l'] -= 2;
            if(mp['l'] == 0) mp.erase('l');
            mp['o'] -= 2;
            if(mp['o'] == 0) mp.erase('o');
            mp['n']--;
            if(mp['n'] == 0) mp.erase('n');
        }
        return words_formed;
    }
};