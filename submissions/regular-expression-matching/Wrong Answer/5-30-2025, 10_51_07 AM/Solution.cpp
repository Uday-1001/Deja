// https://leetcode.com/problems/regular-expression-matching

class Solution {
public:
    bool matching(string s , string p , int i , int j)
    {
        //base case 
        if(i == s.size() && j == p.size()) return true;

        if(i == s.size() && j<p.size())
        {
            while(j<p.size())
            {
                if(j+1 < p.size() && p[j+1] != '*')
                return false;
                j += 2;
            }
            return true;
        }

        //ek case hum solve karenge baaki ka recursion karega
        //if current character has '*' 
        if(j+1 < p.size() && p[j+1] == '*')
        {
            bool take = (i<s.size() && (p[j] == s[i] || p[j] == '.') && matching(s , p , i+1 , j));
            bool not_take = matching(s , p , i , j+2);

            return take || not_take;
        }
        //if current character matches or has '.'
        if(i<s.size() && j<p.size() &&(s[i] == p[j] || p[j] == '.'))
        {
            return matching(s , p , i+1 , j+1);
        }
    //any other invalid cases come here
    return false;
    }

    bool isMatch(string s, string p) {
        int i = 0;
        int j = 0;

        bool ans = matching(s , p , i , j);
        return ans;
    }
};