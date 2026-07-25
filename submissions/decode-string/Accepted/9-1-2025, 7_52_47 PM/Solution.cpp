// https://leetcode.com/problems/decode-string

class Solution {
public:
    string decodeString(string s) {
        
        stack<int> countStack;
        stack<string> stringStack;

        int curr_num = 0;
        string curr_string = "";

        for(int i=0 ;  i<s.size() ; i++)
        {
            char ch = s[i];

            if(isdigit(ch))
            {
                curr_num = curr_num * 10 + (ch -'0');
            }
            else if(ch == '[')
            {
                countStack.push(curr_num);
                stringStack.push(curr_string);
                curr_num = 0;
                curr_string = "";
            }
            else if(ch == ']')
            {
                int repetitions = countStack.top(); countStack.pop();
                string repeated_string = stringStack.top(); stringStack.pop();

                string temp = "";
                for(int i=0; i<repetitions ; i++)
                {
                    temp += curr_string;
                }
                curr_string = repeated_string + temp;
            }
            else
            {
                curr_string += ch;
            }
        }
    return curr_string;
    }     
};