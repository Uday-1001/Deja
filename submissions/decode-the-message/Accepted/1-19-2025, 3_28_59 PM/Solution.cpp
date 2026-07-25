// https://leetcode.com/problems/decode-the-message

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> map;
        int start = 'a';
       
        char spaces = ' ';
        map[spaces] = spaces;
        
        int index = 0;
        while(index<key.size() && start<='z')
        {
            char curr_key_char = key[index];
            if(map.find(curr_key_char) != map.end())
            {
                index++;
            }
            else
            {
                map[curr_key_char] = start;
                start++;
                index++;
            }
        }

        string ans = "";
        for(char ch : message)
        {
            char message_char = ch;
            ans .push_back(map[message_char]);
        }
    return ans ;
    }
};