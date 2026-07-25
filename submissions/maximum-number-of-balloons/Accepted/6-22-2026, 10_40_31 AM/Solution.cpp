// https://leetcode.com/problems/maximum-number-of-balloons

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>hash(26 , 0);

        for(auto it : text) hash[it - 'a']++;

        return min({hash['b' - 'a'] , hash['a' - 'a'] , hash['l' - 'a'] / 2 , hash['o' - 'a'] / 2 , hash['n' - 'a']
        });
    }
};