// https://leetcode.com/problems/decode-the-message

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>mp;
        int spaces = ' ';
        mp[spaces] = spaces;
        int index = 0;
        int start = 'a';

        while(index < key.size() && start <= 'z')
        {
            if(mp.find(key[index]) != mp.end())
            {
                index ++;
            }
            else
            {
                mp[key[index]] = start;
                start++;
                index++;
            }
        } 
        string ans = "";
        for(int i = 0 ; i<message.size() ; i++)
        {
            char messagechar = message[i];
            char mappedchar = mp[messagechar];
            ans.push_back(mappedchar);
        }
    return ans;
    }
};