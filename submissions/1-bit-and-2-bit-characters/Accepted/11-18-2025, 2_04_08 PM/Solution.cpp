// https://leetcode.com/problems/1-bit-and-2-bit-characters

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool hasOneBit = false;
        for(int i=0 ; i<bits.size() ;)
        {
            if(bits[i] == 1)
            {
                i += 2;
                hasOneBit = false;
            } 
            else
            {
                i++;
                hasOneBit = true;
            }
        }
    return hasOneBit;
    }
};