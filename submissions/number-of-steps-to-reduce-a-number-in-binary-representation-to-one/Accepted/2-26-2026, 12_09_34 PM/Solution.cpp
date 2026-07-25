// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one

class Solution {
public:
    int numSteps(string s) {        
        int steps = 0;

        while(s != "1")
        {
            if(s.back() == '0') 
            {
                s.pop_back();
            }
            else
            {
                int i = s.size() - 1;
                while(i >= 0 and s[i] == '1')
                {
                    s[i] = '0';
                    i--;
                }
                if(i >= 0) s[i] = '1'; 
                else 
                {
                    s = '1' + s;
                }
            }
            steps++;
        }
    return steps;
    }
};