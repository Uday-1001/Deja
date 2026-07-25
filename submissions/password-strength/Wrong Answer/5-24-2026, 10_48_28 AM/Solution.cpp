// https://leetcode.com/problems/password-strength

class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char>stlower;
        unordered_set<char>stupper;
        unordered_set<int>number;
        unordered_set<char>special;

        int i = 0;
        while(i < password.size())
        {
            char ch = password[i];
            if(ch >= 'a' and ch <= 'z') 
            {
                stlower.insert(ch);
                i++;
            }
            else if(ch >= 'A' and ch <= 'Z') 
            {
                stupper.insert(ch);
                i++;
            }
            else if(ch == '!' or ch == '@' or ch == '#' or ch == '$') 
            {
                special.insert(ch);
                i++;
            }
            else 
            {
                int num = 0;
                while(i < password.size() and isdigit(ch - '0'))
                {
                    num += (ch - '0') * 10;
                    i++;
                }
                number.insert(num);
                i++;
            }
        }
        return (stlower.size() + (stupper.size() * 2) + (special.size() * 5) + (number.size() * 3)); 
    }
};