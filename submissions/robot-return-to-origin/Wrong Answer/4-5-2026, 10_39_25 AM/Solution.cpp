// https://leetcode.com/problems/robot-return-to-origin

class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int>mp;

        for(auto ch : moves) mp[ch]++;
        if(mp.size() == 2 or mp.size() == 4) return true;
        return false;
    }
};