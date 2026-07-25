// https://leetcode.com/problems/decode-string

class Solution {
public:
    string decodeString(string s) {
        stack<int>countStack;
        stack<string>stringStack;
        int curr_num = 0;
        string curr_string = "";

        for(int i=0 ; i<s.size() ; i++)
        {
            char ch = s[i];

            //if the element is a number -> then form the whole number
            if(isdigit(ch))
            {
                curr_num = curr_num * 10 + (ch - '0');
            }
            //if we get an open bracket -> we push the evaluated no. and the current string into the stack 
            else if(ch == '[')
            {
                countStack.push(curr_num);
                stringStack.push(curr_string);
                //reset both the parameters
                curr_num = 0;
                curr_string = "";
            }
            //we evaluate the repeated string and also the production of this bracket
            else if(ch == ']')
            {
                int repeatedTimes = countStack.top();  countStack.pop();
                string repeated_string = stringStack.top();  stringStack.pop();
                
                string temp = "";
                for(int i=0 ; i<repeatedTimes ; i++)
                {
                    temp += curr_string;
                }
                curr_string = repeated_string + temp;
            }
            //we guarenteed get a character -> so simply add it into the string 
            else
            {
                curr_string += ch;
            }
        }
    return curr_string;
    }
};