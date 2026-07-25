// https://leetcode.com/problems/decode-the-message

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,int> map;
        char start = 'a';
        char spaces = ' ';
        map[spaces] = spaces;
        
        int i=0;

        while(i < key.size() && start <= 'z')
        {
            if(map.find(key[i]) == map.end())
            {
                map[key[i]] = start;
                start++;
                i++;
            }
            else
            {
                i++ ;
            }
        }

        for(int i =0 ; i<message.size() ; i++)
        {
            message[i] = map[message[i]];
        }
    return message;
    }
};