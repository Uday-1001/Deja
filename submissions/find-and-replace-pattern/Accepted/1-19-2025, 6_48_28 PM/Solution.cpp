// https://leetcode.com/problems/find-and-replace-pattern

class Solution {
public:
    void normalization(string &str)
    {
        unordered_map<char,char> map;
        char start='a';

        for(int i =0 ; i<str.length() ; i++)
        {
            char character = str[i];
            if(map.find(character) == map.end())
            {
                map[character] = start;
                start++;
            }
        
            str[i] = map[str[i]]; 
        }
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        normalization(pattern);
        vector<string>ans;
        
        for(string curr_word : words)
        {
            string wordcopy = curr_word;
            normalization(wordcopy);
            if(wordcopy.compare(pattern) == 0)
            {
                ans.push_back(curr_word);
            }
        }
    return ans ;
    }
};