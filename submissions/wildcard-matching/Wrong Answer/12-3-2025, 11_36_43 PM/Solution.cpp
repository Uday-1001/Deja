// https://leetcode.com/problems/wildcard-matching

class Solution {
public:
    bool byrec(string s , string p , int  i , int  j)
    {
        //base cases
        if(i == s.size() and j == p.size()) return true;
        if(j == p.size()) return false;
        if(i == s.size())
        {
            while(j < p.size())
            {
                if(p[j] != '*') return false;
                j++;
            }
        return true;
        }

        //ek case hum solve karenge 
        //matching case 
        bool ans = false;
        if(p[j] == '?' or s[i] == p[j])
        {
            return byrec(s , p , i+1 , j+1);
        }
        else 
        {
            //non matching case
            bool op1 = byrec(s , p , i+1 , j);
            bool op2 = byrec(s , p , i , j+1);
            ans = op1 or op2;
        }
        return ans;
    }

    bool isMatch(string s, string p) {
        return byrec(s , p , 0 , 0);
    }
};