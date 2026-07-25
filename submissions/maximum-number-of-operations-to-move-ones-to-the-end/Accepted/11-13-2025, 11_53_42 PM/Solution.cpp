// https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end

class Solution {
public:
    int maxOperations(string s) {
        int one_count = 0;
        int opr = 0;
        bool hasZero = false;
        for(int i=0 ; i<s.size() ; i++)
        {
            if(s[i] == '1')
            {
                one_count++;
                hasZero = false;
            } 
            else if(s[i] == '0' and hasZero == false)
            {
                hasZero = true;
                opr += one_count;
            }
        }
    return opr;
    }
};