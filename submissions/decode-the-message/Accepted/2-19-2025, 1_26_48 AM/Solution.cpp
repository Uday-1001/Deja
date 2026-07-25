// https://leetcode.com/problems/decode-the-message

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>mapping;
        char space = ' ';
        mapping[space] = space;

        char start = 'a';
        int index = 0;

        while(index < key.size() && start<= 'z')
        {
            char curr_char = key[index];

            if(mapping.find(curr_char) == mapping.end())
            {
                mapping[curr_char] = start++;
                index++;
            }
            else
            index++;
        }

        string ans = "";

        for(int i =0 ; i<message.size() ; i++)
        {
            char mssg_char = message[i];

            ans.push_back(mapping[mssg_char]); 
        }
    return ans ;
    }
};