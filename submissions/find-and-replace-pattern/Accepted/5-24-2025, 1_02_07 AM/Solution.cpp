// https://leetcode.com/problems/find-and-replace-pattern

class Solution {
public:
    void normalise(string &s)
    {
        unordered_map<char,char>mp;
        char start = 'a';
        int index = 0;

        while(index <s.size())
        {
            if(mp.find(s[index]) != mp.end())
            {
                index++;
            }
            else
            {
                mp[s[index]] = start ;
                start++;
                index++;
            }
        }
        for(int i = 0 ; i<s.size() ; i++)
        {
            char mapped_char = mp[s[i]];
            s[i] = mapped_char;  
        }
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        normalise(pattern);
        vector<string>ans;

        for(auto word : words)
        {
            string copyword = word;
            normalise(copyword);
            if(copyword.compare(pattern) == 0)
            {
                ans.push_back(word);
            }
        }
    return ans;
    }
};