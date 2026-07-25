// https://leetcode.com/problems/neighboring-bitwise-xor

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int count_1 = 0;
        
        for(int i =0 ; i< derived.size(); i++)
        {
            if(derived[i] == 1) count_1 ++;
        }
    return (count_1 % 2 == 0);
    }
};