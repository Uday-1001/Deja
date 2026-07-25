// https://leetcode.com/problems/1-bit-and-2-bit-characters

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int zero_count = 0;
        int one_count = 0;
        for(auto num : bits)
        {
            if(num == 1) one_count++;
            else zero_count++;
        }  
    return (zero_count > one_count);
    }
};