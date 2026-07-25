// https://leetcode.com/problems/1-bit-and-2-bit-characters

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        return bits.size() & 1;
    }
};