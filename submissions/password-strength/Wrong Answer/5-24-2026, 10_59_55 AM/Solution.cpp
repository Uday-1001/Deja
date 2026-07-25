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
            else if(isdigit(ch))
            {
                int num = 0;
                int j = i;
                while(j < password.size() and isdigit(password[j]))
                {
                    num = num * 10 + (password[j] - '0');
                    j++;
                }
                number.insert(num);
                i = j;
            }
            else i++;
        }
        return (stlower.size() + (stupper.size() * 2) + (special.size() * 5) + (number.size() * 3)); 
    }
};