// https://leetcode.com/problems/decode-the-message

class Solution {
public:
    string decodeMessage(string key, string message) {
        
        unordered_map<char,char>map;
        char spaces=' ';
        map[spaces]=spaces;

        int index =0;
        char startingchar='a';

        while(startingchar <='z' && index<key.length()){

            char keycurrentchar= key[index];

            if(map.find(keycurrentchar) != map.end()){
                
                index ++;
            }
            else
            {
                map[keycurrentchar] = startingchar;
                startingchar ++;
                index ++;
            }
        }
        string ans ="";
        for(int i=0; i<message.length(); i++)
        {
            char msgchar= message[i];
            char mappedchar = map[msgchar];
            ans.push_back(mappedchar);
        }
        return ans;
    }
};