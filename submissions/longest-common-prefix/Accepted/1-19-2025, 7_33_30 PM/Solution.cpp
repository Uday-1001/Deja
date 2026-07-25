// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int i=0;
        while(true)
        {
            char curr_char =0;
            for(auto curr_str : strs)
            {//out of bound condition jab koi string pehle khatam ho jaye dusro se
                if(i>=curr_str.size())
                {
                    //curr_char ko 0 isiliye le rhe kyuki while se bahar aane ke liye koi condition to chahiye
                    curr_char =0;
                    break;
                }

                if(curr_char == 0)
                curr_char = curr_str[i];
                else if(curr_str[i] != curr_char)
                {
                    curr_char =0;
                    break;
                }
            }
            // while loop se bahar aane ka tareeka 
            if(curr_char == 0)
            break;
            else
            ans.push_back(curr_char);
            i++;
        }
    return ans;  
    }
};