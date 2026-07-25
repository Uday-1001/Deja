// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one

class Solution {
public:
    int stringToBinary(string &s)
    {
        int val = 0;
        int n = s.size();
        for(int i = n-1 ; i>=0 ; i--)
        {
            val += ((s[n-1-i] - '0') * pow(2 , i));
        }
    return val;
    }

    int numSteps(string s) {
        int n = stringToBinary(s);
        int count = 0;
        while(n > 1)
        {
            if(n & 1) n++;
            else n /= 2; 
            count++;
        } 
    return count;
    }
};