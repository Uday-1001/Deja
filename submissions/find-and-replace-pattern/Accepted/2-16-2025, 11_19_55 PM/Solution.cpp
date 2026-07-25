// https://leetcode.com/problems/find-and-replace-pattern

class Solution {
public:
    void normalize(string &s)
    {
        char start = 'a';
        unordered_map<char,char>mapping;

        for(int i=0 ; i<s.size() ; i++)
        {
            int curr_char = s[i];
            if(mapping.find(curr_char) == mapping.end())
            {
                mapping[curr_char] = start++;
            }
            s[i] = mapping[s[i]];
        }  
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        normalize(pattern);
        vector<string>ans ;

        for(auto str : words)
        {
            string wordcopy = str;
            normalize(wordcopy);

            if(wordcopy.compare(pattern) == 0)
            {
                ans.push_back(str);
            }
        }
    return ans ;
    }
};