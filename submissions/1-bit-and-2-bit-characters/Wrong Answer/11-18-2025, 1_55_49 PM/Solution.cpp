// https://leetcode.com/problems/1-bit-and-2-bit-characters

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size() == 2 and bits[0] == 0) return true;
        return bits.size() & 1;
    }
};