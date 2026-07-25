// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i =0;
        string ans = "";

        while(true)
        {
            char curr_char = 0;

            for(auto str : strs)
            {
                if(i>=str.size())
                {
                    curr_char = 0 ;
                    break;
                }
                if(curr_char == 0)
                {
                    curr_char = str[i];
                }
                
                else if(curr_char != str[i])
                {
                    curr_char = 0;
                    break;
                }
            }
            if(curr_char == 0)
            {
                break;
            }
            else 
            ans.push_back(curr_char);
            i++;
        }
    return ans;
    }
};